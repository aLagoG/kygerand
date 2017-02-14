#define _CRT_SECURE_NO_DEPRECATE
#define ALL(x) x.begin(), x.end()

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, b;
	scanf("%d %d", &n, &b);
	vector<int> lst(n);
	int i = 0;
	while (n--) scanf("%d",&lst[i++]);
	printf(binary_search(ALL(lst), b)?"Si esta\n":"No esta\n");
}