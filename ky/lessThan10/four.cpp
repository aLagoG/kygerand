#include <stdio.h>
#include <algorithm>
#include <vector> 

using namespace std;

int main() {
	int n,tot;
	scanf("%d", &n);
	vector<int> a(n);
	tot=n;
	while(n--) scanf("%d", &a[n]);
	sort(a.begin(),a.end());
	printf("%d\n",a[0]);
	for(int i=0;i<tot-1;i++){
		if(a[i]!=a[i+1]){
			printf("%d\n",a[i+1]);
		}
	}
}