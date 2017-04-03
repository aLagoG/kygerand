#include <stdio.h>
#include <math.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int sqr = sqrt(n)+1;
		// printf("------%d\n",n);
		int sum = 1;
		for(int i=2;i<sqr;i++){
			if(n%i==0){
				// printf("%d %d\n",i,n/i);
				sum += i;
				if(i*i!=n){
					sum += n/i;
				}
			}
		}
		// printf("--%d--\n",sum);
		if(sum<n){
			printf("deficient\n");
		}else if(sum==n){
			printf("perfect\n");
		}else{
			printf("abundant\n");
		}
	}
}