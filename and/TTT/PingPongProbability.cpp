//2156
#include <stdio.h>

using namespace std;

double tree(int n, int cn, double p, double q, bool w, bool lw){
        if(cn==n){
				if(!w){
					return 0;
				}
                return (lw^w)?p:q;
        }
        double sum = 0;
        sum += tree(n,cn+1,p,q,true,w);
        sum += tree(n,cn+1,p,q,false,w);
        return sum*((lw^w)?p:q);
}

int main (){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		double p, q, res;
		scanf("%d %lf",&n,&p);
		q = 1 - p;
		res = tree(n,1,p,q,true,false);
		res += tree(n,1,p,q,false,false);
		printf("%.5lf\n",res);
	}
}
