//2670
#include <bits/stdc++.h>

using namespace std;

vector<int> graph[501];
int nodes[501];

typedef pair<int, int> pii;

int n,m,k,cnt;

int dfs(int node, int len){
	if(node==n){
		return 1;
	}
	if(len==k){
		return 0;
	}
	int c = 0;
	for(auto i: graph[node]){
		c+= dfs(i,len+1);
	}
	nodes[node] += c;
	return c;
}

void getRes(){
	int max,second;
	do{
		dfs(1,0);
		int idx;
		max=-1;
		second =-1;
		// printf("----\n");
		for(int i=2;i<n;i++){
			// if(nodes[i]){
			// 	printf("%d %d\n",i,nodes[i]);
			// }
			if(nodes[i]>max){
				second = max;
				max = nodes[i];
				idx = i;
			}else if(nodes[i]>second){
				second = nodes[i];
			}
		}
		if(!max){
			return;
		}
		cnt++;
		graph[idx].clear();
		memset(nodes,0,sizeof nodes);
	}while(second);
}

int main(){
	int lst;
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		memset(nodes,0, sizeof nodes);
		cnt = 0;
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			graph[a].push_back(b);
		}
		// bfs();
		getRes();
		printf("%d\n",cnt);
		lst = n;
		for(int i=1;i<n;i++){
			graph[i].clear();
		}
	}
}