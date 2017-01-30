#define _CRT_SECURE_NO_DEPRECATE
#define ALL(x) x.begin(), x.end()

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	scanf("%d", &n);
	vector<int> arr(n, 0);
	while (n--) scanf("%d",&arr[n]);
	sort(ALL(arr));
	//arr.resize(unique(ALL(arr)) - arr.begin());
	//for(auto hn : arr) printf("%d\n", hn);
	for (int i = 0; i < (int)arr.size(); i++) {
		if(i==0||arr[i]!=n) {
			n = arr[i];
			printf("%d\n", arr[i]);
		}
	}
}
