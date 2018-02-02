//2624
#include <stdio.h>
#include <algorithm>

using namespace std;

int d[50];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int m, n;
		scanf("%d %d",&m,&n);
		for(int i=0;i<n;i++){
			scanf("%d",&d[i]);
		}
		sort(d,d+n);
		int i=0;
		int sum = 0;
		for(;i<n;i++){
			sum += d[i];
			if(sum>m){
				break;
			}
		}
		printf("%d\n",i);
	}
}