//3411
#include <stdio.h>
#include <math.h>

double PI = acos(0) * 2.0;

int main(){
	int n;
	scanf("%d",&n);
	double circ;
	double sq;
	double rad;
	while(n--){
		scanf("%lf",&rad);
		circ = PI*rad*rad;
		sq = 2*rad*rad;
		printf("%.2lf\n",circ-sq);
	}
}