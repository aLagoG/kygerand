#include <stdio.h>
#include <string.h>
#include <math.h>

#define M 5001
#define MD 1000000007

typedef unsigned long long llu;

int div[M];

int divisores(int n){
	int cnt = 1;
	int sqr = sqrt(n)+1;
	for(int i=2;i<sqr;i++){
		if(n%i==0){
			cnt++;
			if(i*i!=n){
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	memset(div,0,sizeof div);
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		llu con = 0, opc = 1; 
		scanf("%d %d",&n,&k);
		for(int i=2;i<=n;i++){
			if(!div[i]){
				div[i] = divisores(i);
			}
			// printf("--%d %d--\n", i,div[i]);
			if(div[i]>k){
				con += k;
				opc *= div[i];
			}else{
				con += div[i];
			}
			con %= MD;
			opc %= MD;
		}
		printf("%llu %llu\n", con, opc);
	}
}