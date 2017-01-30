//2272
#include <stdio.h>
#include <math.h>
typedef unsigned long long ll;
using namespace std;
bool prime(ll n);

int main(){
	int t;
	scanf("%d" ,&t);
	while(t--){
		ll n;
		scanf("%llu", &n);
		ll k = n;
		while(!prime(k)){
			k++;
		}
		printf("%llu\n", k);
	}
}

inline bool prime(ll n){
	if(n==2){
		return true;
	}
	if(n<2||n%2==0){
		return false;
	}
	ll sq = sqrt(n)+1;
	for(ll i=3;i<=sq;i+=2){
		if(n%i==0){
			return false;
	    }
	}
	return true;
}
