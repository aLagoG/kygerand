//3424
#include <stdio.h>
#include <math.h>

int main(){
	double pi = 2*acos(0);
	int t;
	scanf("%d",&t);
	while(t--){
		double l,a;
		scanf("%lf %lf",&l,&a);
		// printf("%lf %lf\n",l,a);
		int n = 360/(180-a);
		double p = l*n;
		// printf("%d %lf\n",n,p);
		double ap = l/(2*tan(pi/n)); 
		double area = (ap * p)/2;
		double cir = pi*ap*ap;
		printf("%.15lf\n",area-cir);
	}
}