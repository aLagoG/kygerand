#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

int main(){
	
	string line;
	unordered_set<string> unique;                                
	int t;
	scanf("%d", &t);
	while(t--){
		cin >> line;
		sort(line.begin(), line.end());
		unique.insert(line);
	}
	printf("%lu", unique.size());
}