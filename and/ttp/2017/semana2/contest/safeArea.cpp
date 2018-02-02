//3408
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

struct point{
	double x,y;
};

inline double area(const point  &a, const point  &b, const point  &c){
	return abs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0);
}

int main(){
	int n;
	scanf("%d",&n);
	string id;
	double max = -1;
	point a,b,c;
	while(n--){
		string nn;
		cin >> nn;
		scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y);
		double ar = area(a,b,c);
		if(ar>max){
			max = ar;
			id = nn;
		}
	}
	cout << id;
	printf(" %.2lf km^2\n", max);
}