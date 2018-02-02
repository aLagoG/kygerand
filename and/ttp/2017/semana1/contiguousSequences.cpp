//2188
#include <stdio.h>
#include <string.h>

typedef long long ll;

ll maxPoints(ll a,ll b){
	if(a==0){
		return -1*b*b;
	}else if(b==0){
		return a*a;
	}
	if(b==1){
		return a*a-1;
	}
	if(a==1){
		ll v = b/2;
		if(b&1){
			return 1-v*v-(v+1)*(v+1);
		}
		return 1-2*v*v;
	}
	ll maxx = 1ULL<<63;
	for(ll i=a+1;i>1;i--){
		ll gb = b/i;
		ll rb = b%i;
		ll ga = a/(i-1);
		ll ra = a%(i-1);
		ll score = (i-2)*(1)+((i-2)*(ga-1)+ga+ra)*((i-2)*(ga-1)+ga+ra)-(rb*(gb+1)*(gb+1) + (i-rb)*(gb)*(gb));
		if(score>maxx){
			maxx=score;
		}
	}
	return maxx;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll a,b;
		scanf("%lld %lld", &a, &b);
		printf("%lld\n",maxPoints(a,b));
	}
}