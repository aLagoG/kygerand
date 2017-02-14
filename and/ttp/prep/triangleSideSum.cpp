//3426
#include <stdio.h>
typedef unsigned long long ll;

int main(){
	ll a,b;
	scanf("%llu %llu", &a, &b);
	ll sum = 0;
	ll min = (a<b?b-a:a-b)+1;
	ll max = a+b-1;
	printf("%llu\n", (max-min+1)*(max+min)/2);
}
