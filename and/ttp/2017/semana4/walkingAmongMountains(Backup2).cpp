//2227
#include <stdio.h>
#include <algorithm>

using namespace std;

typedef unsigned long long ul;

char mp[10][10];
ul mn = 1L<<63;
int x,y;

void search(int i, int j, ul sum){
	if(j==x&&i==y){
		if(sum<mn){
			mn = sum;
		}
		return;
	}
	if(j<x){
		search(i,j+1,sum+max(0,mp[i][j+1]-mp[i][j]));
	}
	if(i<y){
		search(i+1,j,sum+max(0,mp[i+1][j]-mp[i][j]));
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&mp[i][j]);
		}
	}
	scanf("%d %d",&x,&y);
	x--;
	y--;
	search(0,0,0);
	printf("%llu\n",mn);
}