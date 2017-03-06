//3459
#include <stdio.h>

typedef unsigned long long ull;

int main(){
	int t,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&k);
		ull count = 1;
		ull current = 1;
		ull time = 0;
		for(int i=k;i>1;i--){
			current *= i;
			count += current;
			time += i*i*i;
		}
		printf("%llu %llu\n",count,time);
	}
}