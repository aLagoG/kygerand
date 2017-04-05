#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

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
		}
		if(f!=1){
			sum *= f+1;
		}
		sum -= n;
		if(sum<n){
			printf("deficient\n");
		}else if(sum==n){
			printf("perfect\n");
		}else{
			printf("abundant\n");
		}
	}
}