//2105
#include <stdio.h>
#include <string.h>

bool map[1001][1001];
// bool dp[1001][1001];


int n, m;
int count = 0;
// int k,l;
// bool first = true;

inline bool isShore(int i, int j){
	// if(map[i][j]&&!dp[i][j]){
	if(map[i][j]){
		if(i>0&&!map[i-1][j]){
			return true;
		}
		if(i+1<n&&!map[i+1][j]){
			return true;
		}
		if(j>0&&!map[i][j-1]){
			return true;
		}
		if(j+1<m&&!map[i][j+1]){
			return true;
		}
	}
	return false;
}

// void dfs(int i, int j){
// 	if(i==k&&j==l&&!first){
// 		first = false;
// 		return;
// 	}
// 	count++;
// 	dp[i][j] = true;
// 	if(j+1<m&&isShore(i,j+1)){
// 		dfs(i,j+1);
// 	}
// 	if(i+1<n&&isShore(i+1,j)){
// 		dfs(i+1,j);
// 	}
// 	if(j>0&&isShore(i,j-1)){
// 		dfs(i,j-1);
// 	}
// 	if(i>0&&isShore(i-1,j)){
// 		dfs(i-1,j);
// 	}
// 	if(j+1<m&&i+1<n&&isShore(i+1,j+1)){
// 		dfs(i+1,j+1);
// 	}
// 	if(i+1<n&&j>0&&isShore(i+1,j-1)){
// 		dfs(i+1,j-1);
// 	}
// 	if(j>0&&i>0&&isShore(i-1,j-1)){
// 		dfs(i-1,j-1);
// 	}
// 	if(i>0&&j+1<m&&isShore(i-1,j+1)){
// 		dfs(i-1,j+1);
// 	}
// }

int main(){
	char tmp;
	// bool found = false;
	// memset(dp,0,sizeof dp);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%c",&tmp);
			if(tmp!='-'&&tmp!='+'){
				j--;
				continue;
			}
			map[i][j] = tmp=='-'?false:true;
			// if(!found&&map[i][j]){
			// 	found = true;
			// 	k = i;
			// 	l = j;
			// }
		}
	}
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		printf("%d ",map[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// int i=k,j=l;
	// dfs(k,l);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]&&isShore(i,j)){
				count++;
			}
		}
	}
	printf("%d\n",count);
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		printf("%d ",dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
}