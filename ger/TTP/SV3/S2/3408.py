#include <cstdio>
#include <iostram>
#include <stdlib.h>
using namespace std;

int main(){
	float big = 0.0;
	char[1000] ignore;
	float xa, ya, xb, yb, xc, yc;
	int t;
	while(t--){
		cin >> ignore;
		scanf("%f %f %f %f %f %f", &xa, &ya, &xb, &yb, &xc, &yc);
		printf("%f %f %f %f %f %f", xa, ya, xb, yb, xc, yc);
	}
	//area = abs(((xa*(yb-yc))+(xb*(yc-ya))+(xc*(ya-yb)))/2)

	return 0;
}


// big = 0.0
// case = 0
// for t in xrange(input()):
// 	xa, ya, xb, yb, xc, yc = [i for i in raw_input().split()][1:]

// 	xa = float(xa)
// 	ya = float(ya)
// 	xb = float(xb)
// 	yb = float(yb)
// 	xc = float(xc)
// 	yc = float(yc)

	
// 	if area > big:
// 		case = t
// 		big = area
// print "Area%d %.2f km^2" % (case+1, big)
