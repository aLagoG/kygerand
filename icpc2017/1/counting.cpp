#include <stdio.h>
#include <string.h>
#include <math.h>

#define M 5001
#define MD 1000000007
#define NP 20

typedef unsigned long long llu;

int div[M];
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

int divisores(int n){
	int sum = 1;
	int sqr = sqrt(n);
	for(int i=0;primes[i]<=sqr;i++){
		int cnt = 0;
		while(n%primes[i]==0){
			cnt++;
			n /= primes[i];
		}
		sum *= cnt+1;
	}
	if(n!=1){
		sum <<= 1;
	}
	return sum-1;
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