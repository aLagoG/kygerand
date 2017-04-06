//1531
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>

using namespace std;

int ch[100001];
int tree[100001];
// vector<int> graph[100001];
int last[100001];

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(ch,0,sizeof ch);
		memset(tree,0,sizeof tree);
		memset(last,-1,sizeof last);
		int n;
		scanf("%d",&n);
		int v;
		for(int i=1;i<=n;i++){
			scanf("%d",&v);
			tree[i] = v;
			// graph[n].push_back(i);
			// printf("%d ",tree[i]);
		}
		int count = n;
		for(int i=n-1;i>0;i--){
			ch[tree[i]] += ch[i]+1;
			if(last[tree[i]]==-1){
				last[tree[i]] = ch[i]+1;
			}else if(last[tree[i]]!=ch[i]+1&&last[tree[i]]!=-2){
				last[tree[i]] = -2;
				count--;
			}
		}
		printf("%d",count);
		for(int i=1;i<=n;i++){
			if(last[i]!=-2){
				printf(" %d",i);
			}
		}
	}
}