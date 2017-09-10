//272 TEX Quotes
#include <cstdio>

using namespace std;

int main(){
	char c;
	bool opened = false;
	while(scanf("%c", &c) != EOF){
		if(c == 34){
			if(!opened){
				printf("%c", 96);
				printf("%c", 96);
				opened = true;
			}else{
				printf("%c", 39);
				printf("%c", 39);
				opened = false;
			}
		}else{
			printf("%c", c);
		}
	}
}