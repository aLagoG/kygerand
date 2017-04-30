#define ALL(x) x.begin(), x.end()

#include<stdio.h>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;

bool daycmp(array<int, 3> a, array<int, 3> b){return a[0] < b[0];}
bool monthcmp(array<int, 3> a, array<int, 3> b){return a[1] < b[1];}
bool datecmp(array<int, 3> a, array<int, 3> b){return a[2] < b[2];}

void printer(vector<array<int, 3>> v){
	for(auto x: v){
		printf("%d %d %d\n", x[0], x[1], x[2]);
	}
	printf("---\n")
}

int main(){
	int n;
	scanf("%d", &n);
	vector<array<int, 3>> dates(n);

	while(n--) scanf("%d %d %d", &dates[n][0], &dates[n][1], &dates[n][2]);
	
	sort(ALL(dates), daycmp);
	printer(dates);
	sort(ALL(dates), monthcmp);
	printer(dates);
	sort(ALL(dates), datecmp);
	printer(dates);

}