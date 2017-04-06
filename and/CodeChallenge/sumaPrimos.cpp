#include <stdio.h>
#include <array>
#include <algorithm>

#define ALL(x) x.begin(), x.end()

using namespace std;

#define N 46358
#define M 4794

typedef unsigned long long ll;
 

array<ll,M> primes;
array<bool,N> arr;

void cribaE(){
	ll p = 2;
	ll c = 0;
	while(p<N){
		primes[c++] = p;
		for(ll i=p;i<N;i+=p){
			arr[i] = true;
		}
		while(p<N&&arr[++p]);
	}
}

int main(){
	cribaE();
	int t;
	scanf("%d",&t);
	while(t--){
		int sum;
		scanf("%d",&sum);
		// printf("--%d--\n",sum);
		int mx = sum/2+1;
		// printf("%d\n",mx);
		for(int i=0;i<sum/2;i++){
			// printf("%llu %llu\n",primes[i],sum-primes[i]);
			if(binary_search(ALL(primes),sum-primes[i])){
				printf("%llu %llu\n",primes[i],sum-primes[i]);
				break;
			}
		}
	}
}