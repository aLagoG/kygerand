//3748
#include <stdio.h>

typedef unsigned long long ll;

ll gcd(ll a, ll b){
	ll res = 1;
	int d =0;
	if(a==b){
		return a;
	}
	while(!(a&1)&&!(b&1)){
		a >>= 1;
		b >>= 1;
		res = 1<<(++d);
	}
	while(a!=b){
		if(!(a&1)){
			a >>= 1;
		}else if(!(b&1)){
			b >>= 1;
		}else if(a>b){
			a = (a-b)>>1;
		}else{
			b = (b-a)>>1;
		}
	}
	return a*res;
}

int main(){
	ll v1,d1,v2,d2;
	ll t1,t2;
	int count = 1;
	while(scanf("%llu %llu %llu %llu",&v1,&d1,&v2,&d2),v1||d1||v2||d2){
		printf("Case #%d: ",count++);
		if(d1*v2<d2*v1){
			printf("You owe me a beer!\n");
		}else{
			printf("No beer for the captain.\n");
		}
		printf("Avg. arrival time: ");
		ll gd = gcd(v1,v2);
		ll lcm = v1*v2/gd;
		ll sum = lcm/v1*d1+lcm/v2*d2;
		ll div = 2*lcm;
		gd = gcd(sum,div);
		sum /= gd;
		div /= gd;
		printf("%llu",sum);
		if(div>1){
			printf("/%llu",div);
		}
		printf("\n");
	}
}