//3428
#include <stdio.h>
#include <algorithm>
#include <vector>

#define ALL(x) x.begin(),x.end()

using namespace std;

struct point{
	long double x,y;

	bool operator <(const point  &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};

inline long rotation(const point  &a, const point  &b, const point  &c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline long double area(const point  &a, const point  &b, const point  &c){
	// printf("%Lf * (%Lf-%Lf)+ %Lf * (%Lf-%Lf)+ %Lf * (%Lf-%Lf)\n",a.x,b.y,c.y,b.x,c.y,a.y,c.x,a.y,b.y);
	return abs((a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y))/2.0);
}

int main(){
	int n;
	scanf("%d", &n);
	vector<point> all(n);
	for(int i=0;i<n;i++){
		scanf("%Lf %Lf",&all[i].x,&all[i].y);
	}
	sort(ALL(all));
	// for(auto p: all){
	// 	printf("%.0Lf %.0Lf\n", p.x,p.y);
	// }
	// printf("\n");
	int count = 0;
	vector<point> hull(2*n);
	for(int i=0;i<n;i++){
		while(count>=2 && rotation(hull[count-2], hull[count-1], all[i]) <= 0){
			count--;
		}
		hull[count++] = all[i];
	}
	int t = count+1;
	for(int i=n-2;i>=0;i--){
		while(count >= t && rotation(hull[count-2], hull[count-1], all[i]) <= 0){
			count--;
		}
		hull[count++] = all[i];
	}
	hull.resize(count-1);
	n = hull.size();
	if(n==3){
		printf("%.1Lf\n",area(hull[0],hull[1],hull[2]));
		return 0;
	}
	int a=0,b=1,c=2;
	int pa=0,pb=0,pc=0;
	while(1){
		while(1){
			while(area(hull[a],hull[b],hull[c])<=area(hull[a],hull[b],hull[(c+1)%n])){
				c = (c+1)%n;			
			}
			if(area(hull[a],hull[b],hull[c])<=area(hull[a],hull[(b+1)%n],hull[c])){
				b = (b+1)%n;
				continue; 
			}else{
				break;
			}
		}
		if(area(hull[a],hull[b],hull[c])>area(hull[pa],hull[pb],hull[pc])){
			pa = a;
			pb = b;
			pc = c;
		}
		a = (a+1)%n;		
		if(a==b){
			b=(b+1)%n;
		}
		if(b==c){
			c=(c+1)%n;
		}
		if(a==0){
			break;
		}
	}
	// printf("\n%d %d %d\n",pa,pb,pc);
	printf("%.1Lf\n",area(hull[pa],hull[pb],hull[pc]));
}