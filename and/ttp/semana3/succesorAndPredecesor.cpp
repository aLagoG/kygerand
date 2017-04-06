//3110
#include <stdio.h>

int main(){
	int n;
	scanf("%d",&n);
	n*=2;
	int m = n%3;
	if(m>0){
		printf("%d",m==1?1:3);
	}
	m=n/3;
	while(m--){
		printf("7");
	}
}