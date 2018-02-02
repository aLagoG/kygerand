//3418
#include <stdio.h>
#include <string.h>

long vw[5];
char v[]={'a','e','i','o','u'};

int main(){
	char c;
	memset(vw, 0, sizeof vw);
	while(scanf("%c",&c)!=EOF){
		for(int i=0;i<5;i++){
			if(c==v[i]||c==v[i]-32){
				vw[i]++;
				break;
			}
		}
	}
	for(int i=0;i<5;i++){
		printf("%ld",vw[i]);
		if(i<4){
			printf(" ");
		}
	}
	printf("\n");
}