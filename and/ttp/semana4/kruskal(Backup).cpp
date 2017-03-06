//3557
#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 6000
#define K 6000000000
#define PP 7609
#define LP 77472
typedef unsigned long long ll;

int primes[PP];

void cribaE(){
	bool arr[LP];
	memset(arr,0,sizeof arr);
	ll p = 2;
	int c = 0;
	while(p<LP){
		primes[c++] = p;
		for(ll i=p;i<LP;i+=p){
			arr[i] = true;
		}
		while(p<LP&&arr[++p]);
	}
}

inline bool isPrime(ll p){
	if(p<2){
		return false;
	}
	ll max = (int) ceil(sqrt(p));
	if(max*max==p){
		return false;
	}
	int i = 0;
	while(primes[i]<max){
		if(!(p%primes[i++])){
			return false;
		}
	}
	return true;
}

int main(){
	cribaE();
	int t,n;
	scanf("%d",&t);
	ll k,r;
	while(t--){
		scanf("%d %llu",&n,&k);
		ll turns=0;
		for(int i=0;i<n;i++){
			scanf("%llu", &r);
			ll goal = r;
			while(!isPrime(--goal));
			ll d = r-goal;
			turns += ceil(d/(k+1)*2);
			// if(d%(k+1)){
			// 	win = true;
			// }

		}
		printf("%s\n",turns&1^n&1?"YES":"NO");
	}
}