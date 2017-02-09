//3746
#include <stdio.h>

typedef unsigned long long ll;

inline ll min(ll a,ll b){
	return a<b?a:b;
}

int main(){
	ll n,a,b,c;
	scanf("%llu %llu %llu %llu",&n,&a,&b,&c);
	if(n%4==0&&n>0){
		printf("0");
		return 0;
	}
	ll obj = 0;
	while((obj+n)%4!=0||obj==0){
		obj++;
	}
	ll vals[4];
	vals[0] = a;
	vals[1] = min(2*a,b);
	vals[2] = min(3*a,min(a+vals[1],c));
	vals[3] = min(2*vals[1],min(4*a,vals[0]+vals[2]));
	printf("%llu", vals[obj-1]);
}