//1561
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>

typedef unsigned long long ll;
using namespace std;

int M = 78498;

ll primes[78498]; //78950

int N = 1000001;

void cribaE(){
	bool arr[N];
	memset(arr,0,sizeof arr);
	ll p = 2;
	int c = 0;
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
	int n;
	scanf("%d",&n);
	while(n--){
		ll min, max;
		scanf("%llu %llu",&min, &max);
		ll min2 = ceil(sqrt(min));
		ll max2 = sqrt(max);
		printf("%ld\n",upper_bound(primes,primes+M,max2)-lower_bound(primes,primes+M,min2));
	}
}