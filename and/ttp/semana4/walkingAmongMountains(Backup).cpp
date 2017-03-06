//2227
#include <stdio.h>

char mp[10][10];
int pnt[10][10];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf(" %c",&mp[i][j]);
		}
	}
	int x,y;
	scanf("%d %d",&x,&y);
	pnt[0][0] = 0;
	for(int i=1;i<x;i++){
		pnt[0][i] = mp[0][i]>mp[0][i-1]? pnt[0][i-1]+mp[0][i]-mp[0][i-1]: pnt[0][i-1];
	}
	for(int i=1;i<y;i++){
		pnt[i][0] = mp[i][0]>mp[i-1][0]? pnt[i-1][0]+mp[i][0]-mp[i-1][0]: pnt[i-1][0];
	}
	int t,l;
	for(int i=1;i<y;i++){
		for(int j=1;j<x;j++){
			t = mp[i][j]>mp[i-1][j]? pnt[i-1][j]+mp[i][j]-mp[i-1][j]: pnt[i-1][j];
			l = mp[i][j]>mp[i][j-1]? pnt[i][j-1]+mp[i][j]-mp[i][j-1]: pnt[i][j-1];
			pnt[i][j] = t>l?l:t;
		}
	}
	printf("%d\n",pnt[y-1][x-1]);
}