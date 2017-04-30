#include <cstdio>
using namespace std;

int main(){
	int k;
	char c;
	scanf("%d", &k);
	scanf("%c", &c);
	while(scanf("%c", &c)!= EOF){
		if(65 <= c && c <= 90){
			printf("%c", c+32);
		}else if(97 <= c && c <= 122){
			printf("%c", c-32);
		}else{
			printf("%c",c);
		}
	}
}