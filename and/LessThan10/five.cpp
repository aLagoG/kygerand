#define _CRT_SECURE_NO_DEPRECATE
#define ALL(x) x.begin(), x.end()

#include <stdio.h>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void printDate(array<int,3> s){
	printf("%02d,%02d,%02d\n", s[0],s[1],s[2]);
}

int main() {
	int n;
	scanf("%d",&n);
	vector<array<int, 3>> lst(n);
	while (n--) {
		scanf("%d,%d,%d",&lst[n][0], &lst[n][1], &lst[n][2]);
	}
	//for(auto i: lst) {
	//	printf("%02d,%02d,%02d\n", i[0], i[1], i[2]);
	//}
	sort(ALL(lst), [](array<int, 3> i, array<int, 3> j) {return i[1] < j[1]; });
	for_each(ALL(lst), printDate);
	printf("\n");
	sort(ALL(lst), [](array<int, 3> i, array<int, 3> j) {return i[0] < j[0]; });
	for_each(ALL(lst), printDate);
	printf("\n");
	sort(ALL(lst), [](array<int, 3> i, array<int, 3> j) {return i[2] < j[2]; });
	for_each(ALL(lst), printDate);
	printf("\n");
}