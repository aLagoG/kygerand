#include <stdio.h>
#include <math.h>

typedef unsigned long long ll;

int main(){
	ll n;
	while(scanf("%llu", &n), n){
		// printf("%llu------\n", n);
		// printf("%lf +-+-\n", log2(n));
		// printf("%lld +-+-\n", (ll)log2(n));
		// printf("%lld +-+-\n", 1ll<<(ll)log2(n));
		ll num = n - (1ll<<(ll)log2(n));
		// printf("%llu+++\n", num);
		printf("%llu\n", (num<<1)+1);  
	}
}