#define ALL(x) x.begin(), x.end()

#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int l, query;

int main(){
	scanf("%d %d", &l, &query);
	vector<int> list(l);

	int i = 0;
	while(l--) scanf("%d", &list[i++]);
	printf(binary_search(ALL(list), query) ? "found" : "not found");
}