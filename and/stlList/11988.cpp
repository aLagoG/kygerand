#include <stdio.h>
#include <list>

using namespace std;

list<char> l;

inline void printNClear() {
	while (!l.empty()) {
		printf("%c", l.front());
		l.pop_front();
	}
	printf("\n");
}

int  main() {
	char c;
	auto iter = l.end();
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			printNClear();
			iter = l.end();
		} else {
			if (c == '[') {
				iter = l.begin();
			} else if (c == ']') {
				iter = l.end();
			} else {
				iter = l.insert(iter, c);
				iter++;
			}
		}
	}
	if(!l.empty()){
		printNClear();
	}
}