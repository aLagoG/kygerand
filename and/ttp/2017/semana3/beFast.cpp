//3552
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <list>
#include <queue>

using namespace std;
#define INF INT_MAX

int n;
list<int> *graph;
int lft[10002];
int rgh[10002];
int dst[10002];

bool bfs(){
    queue<int> q;
    for (int l=1; l<=n; l++){
        if (!lft[l]){
            dst[l] = 0;
            q.push(l);
        }else{ 
        	dst[l] = INF;
    	}
    }
    dst[0] = INF;
    while (!q.empty()){
        int l = q.front();
        q.pop();
        if (dst[l] < dst[0]){
            for (auto r: graph[l]){
                if (dst[rgh[r]] == INF){
                    dst[rgh[r]] = dst[l] + 1;
                    q.push(rgh[r]);
                }
            }
        }
    }
    return (dst[0] != INF);
}

bool dfs(int node){
    if (node){
        for (auto r: graph[node]){
            if (dst[rgh[r]] == dst[node]+1&&dfs(rgh[r]) == true){
                rgh[r] = node;
                lft[node] = r;
                return true;
            }
        }
        dst[node] = INF;
        return false;
    }
	return true;
}

int getMatching(){
    memset(lft, 0, sizeof lft);
    memset(rgh, 0, sizeof rgh);
    int result = 0;
    while (bfs()){
        for (int u=1; u<=n; u++){
            if (lft[u]==0 && dfs(u)){
                result++;
            }
        }
    }
    return result;
}

int main(){
	int m, l, r;
	while(scanf("%d %d",&n,&m)&&n&&m){
		// n++;
		graph = new list<int>[++n+1];
		for(int i=0;i<m;i++){
			scanf("%d %d",&l,&r);
			graph[l+1].push_back(r+1);
		}
		printf("%d\n",getMatching());
		delete[] graph;
	}
}