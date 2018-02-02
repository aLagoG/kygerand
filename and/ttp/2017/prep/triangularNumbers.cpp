//2430
#include <stdio.h>
#include <math.h>

int main(){
	long double n;
	while(scanf("%Lf", &n),n){
		if(fmod(sqrtl(8*n+1),1)==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}
