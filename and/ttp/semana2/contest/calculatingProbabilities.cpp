//3051
#include <stdio.h>

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double n,m;
		scanf("%lf %lf",&n,&m);
		printf("%.2lf\n",n/m);
	}
}