#include <cstdio>
#include <iostream>
#include <math.h> 
#include <string.h>
using namespace std;

int main(){
	double big = -1.0;
	char ignore[1000];
	double xa, ya, xb, yb, xc, yc;
	int t;
	scanf("%d",&t);

	double area;
	string name;
	string nn;
	while(t--){
		cin >> nn;
		scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &xb, &yb, &xc, &yc);
		area = fabs( ( (xa*(yb-yc)) + (xb*(yc-ya)) + (xc*(ya-yb)) )/2 );

		if(area > big){
			big = area;
			name = nn;
		}

	}
	cout << name;
	printf(" %.2f km^2", big);

	return 0;
}
