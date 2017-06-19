#include <stdio.h>

int main(){
	int n;
	while(scanf("%d", &n), n){
		int a=0,b=0,c=0;
		for(int i=0;i<32;i++){
			if(n>>i&1){
				c++;
				if(c&1){
					a |= 1<<i;
				}else{
					b |= 1<<i;
				}
			}
		}
		printf("%d %d\n", a,b);
	}
}