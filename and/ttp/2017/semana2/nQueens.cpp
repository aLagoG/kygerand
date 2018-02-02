//1074
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> st;
int n;
int sol;

void dfs(int idx){
	if(idx==n){
		printf("%d :",++sol);
		for(int i=0;i<n;i++){
			printf(" %d",st[i]+1);
		}
		printf("\n");
		return;
	}
	for(int i=0;i<n;i++){
		int val1 = idx+i;
		int val2 = idx-i;
		bool vl = true;
		// printf("-----idx:%d i:%d v1:%d v2:%d----\n",idx,i,val1,val2);
		for(int j=0;j<idx;j++){
			// printf("j:%d v1:%d v2:%d st:%d\n",j,j+st[j],j-st[j],st[j]);
			if(i==st[j]||j+st[j]==val1||j-st[j]==val2){
				vl = false;
				break;
			}
		}
		if(vl){
			// printf("%d %d\n",idx,i);
			st[idx] = i;
			dfs(idx+1);
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		st = vector<int>(n,0);
		sol=0;
		for(int i=0;i<n;i++){
			st[0]=i;
			dfs(1);
		}
		if(sol==0){
			printf("No Solution.\n");
		}
	}
}