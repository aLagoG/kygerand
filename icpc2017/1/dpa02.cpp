#include <stdio.h>
#include <string.h>

#define NP 78498
#define MAXP 999999

typedef unsigned long long ull;

bool crib[MAXP];
int primes[NP];

int main(){
	memset(crib,0,sizeof crib);
	int cnt = 0;
	int pr = 2;
	while(pr<MAXP){
		primes[cnt++] = pr;
		for(int i=pr;i<MAXP;i+=pr){
			crib[i] = 1;
		}
		while(pr<MAXP&&crib[++pr]);
	}

	int t;
	scanf("%d",&t);
	while(t--){
		ull n, f;
		scanf("%llu",&n);
		f = n;
		ull n2 = 2*n;
		ull sum = 1;
		for(int i=0;f>1&&i<NP;i++){
			ull last = 1;
			ull local = 1;
			while(!(f%primes[i])){
				last *= primes[i];
				local += last;
				f /= primes[i];
			}
			sum *= local;
			if(sum>n2){
				printf("abundant\n");
				break;
			}
		}
		sum -= n;
		if(sum<n){
			printf("deficient\n");
		}else if(sum==n){
			printf("perfect\n");
		}
	}
}