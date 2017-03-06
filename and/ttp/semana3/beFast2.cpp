#include <iostream>
#include <string.h>
#include <list>

using namespace std;

int n;
list<int> *graph;
bool done[10002];
int lft[10002];

bool dfs(int u){
    for (auto v: graph[u]){
        if (!done[v]){
            done[v] = true; 
            if (lft[v] < 0 || dfs(lft[v])){
                lft[v] = u;
                return true;
            }
        }
    }
    return false;
}

int getMatching(){
    memset(lft, -1, sizeof(lft));
    int result = 0;
    for (int u = 0; u < n; u++){
        memset(done, 0, sizeof(done));
        if (dfs(u)){
            result++;
        }
    }
    return result;
}

int main(){
    int m, l, r;
	while(scanf("%d %d",&n,&m)&&n&&m){
		graph = new list<int>[n];
		for(int i=0;i<m;i++){
			scanf("%d %d",&l,&r);
			graph[l].push_back(r);
		}
		printf("%d\n",getMatching());
		delete[] graph;
	}
}