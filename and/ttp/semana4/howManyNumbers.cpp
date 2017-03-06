//3327
#include <stdio.h>

using namespace std;
typedef unsigned long long ul;

ul fac[19];
ul pow[19];

void gen(){
	fac[0] = 1;
	pow[0] = 1;
	for(int i=1;i<20;i++){
		fac[i] = i*fac[i-1];
		pow[i] = pow[i-1]*5;
	}
}

int main(){
	gen();
	ul p,n;
	while(scanf("%llu %llu",&p,&n)&&(p||n)){
		ul res = 0;
		if(p){
			res += 2*4*pow[n+p-1]*(fac[n+p-1]/(fac[n]*fac[p-1]));
			if(!n&&p==1){
				res++;
			}
		}
		if(n){
			res += 2*pow[p+n]*(fac[n+p-1]/(fac[n-1]*fac[p]));
		}
		printf("%llu\n",res);
	}

}