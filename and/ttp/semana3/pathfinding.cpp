//1527
#include <stdio.h>
#include <vector>
#include <queue>
#include <bitset>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int n,m;
vector<int> g[101];
bitset<101> v;
vector<int> f[101];

void bfs(){
	int num=n-1;
	pii t;
	queue<pii> q;
	q.push(pii(m,0));
	f[0].push_back(m);
	v[m] = 1;
	while(num&&!q.empty()){
		t = q.front();
		q.pop();
		for(auto i: g[t.first]){
			if(v[i]){
				continue;
			}
			q.push(pii(i,t.second+1));
			v[i] = 1;
			num--;
			f[t.second+1].push_back(i);
			// printf("%d %d --\n",i,t.second+1);	
		}
	}
}

int main(){
	int t;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&t);
			if(t){
				g[i+1].push_back(j+1);
			}
		}
	}
	// for(int i=1;i<n;i++){
	// 	for(auto j: g[i]){
	// 		printf("%d ",j);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	bfs();
	for(int i=0;i<n;i++){
		if(f[i].empty()){
			break;
		}
		sort(f[i].begin(), f[i].end());
		for(auto z: f[i]){
			printf("%d ", z);
		}
		printf("\n");
	}
}