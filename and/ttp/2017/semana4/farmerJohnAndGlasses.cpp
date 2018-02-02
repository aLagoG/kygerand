//3541
#include <stdio.h>

int main(){
	char n;
	while(scanf("%c",&n),n!='\n');
	while(scanf("%c",&n)!=EOF){
		if(n>='a'&&n<='z'){
			n -= 32;
		}else if(n>='A'&&n<='Z'){
			n += 32;
		}
		printf("%c",n);
	}
}