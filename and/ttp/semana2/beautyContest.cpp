//2145
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
		int n;
		scanf("%d",&n);
		int sc[10];
		for(int i=1;i<=n;i++){
			for(int j=0;j<10;j++){
				scanf("%d",&sc[j]);
			}
			sort(sc,sc+10);
			int sum =0;
			for(int j=1;j<9;j++){
				sum += sc[j];
			}
			printf("%d %d\n",i,sum);
		}
}