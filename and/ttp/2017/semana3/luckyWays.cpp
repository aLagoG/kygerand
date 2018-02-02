//3393
#include <stdio.h>
#include <string.h>
#include <unordered_set>

typedef unsigned long ul;

using namespace std;

unordered_set<int> *graph;
bool used[200001];
ul dp[200001];
int n, m, a, b;

ul dfs(int node){
	if(node==b){
		return 1;
	}
	ul res = 0;
	used[node] = 1;
	for(auto child: graph[node]){
		if(!used[child]){
			res += dp[child] ? dp[child] : dfs(child);
		}
	}
	used[node] = 0;
	dp[node] = res;
	return res % 10000007ul;
}

int main(){
	scanf("%d %d %d %d",&n,&m,&a,&b);
	graph = new unordered_set<int>[n+1];
	memset(used, 0, sizeof used);
	memset(dp, 0, sizeof dp);
	int x,y;
	while(m--){
		scanf("%d %d",&x,&y);
		if(graph[y].find(x)!=graph[y].end()){
			graph[y].erase(x);
			continue;
		}
		graph[x].insert(y);
	}
	printf("%lu\n",dfs(a));
}