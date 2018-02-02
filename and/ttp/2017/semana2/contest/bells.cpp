//3346
#include <stdio.h>
#include <algorithm>

using namespace std;

int bells[10001];

int main(){
	int n,b;
	scanf("%d %d",&n,&b);
	for(int i=0;i<n;i++){
		scanf("%d",&bells[i]);
	}
	sort(bells,bells+n);
	int t,v,val,idx;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&v);
		val = b/v;
		idx = upper_bound(bells,bells+n,val)-bells;
		printf("%d\n",n-idx);
	}
}