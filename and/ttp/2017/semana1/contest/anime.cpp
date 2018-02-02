//2520
#include <stdio.h>
#include <set>

using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n, p, j, f;
		scanf("%d %d %d %d",&n,&p,&j,&f);
		set<int> g;
		int res = n-p;
		int res2 = 0;
		for(int i=0;i<j;i++){
			int t;
			scanf("%d",&t);
			if(t>p){
				res--;
			}else{
				res2++;
			}
			g.insert(t);
		}
		set<int> fi;
		for(int i=0;i<f;i++){
			int t;
			scanf("%d",&t);
			if(t>p&&g.find(t)==g.end()){
				res--;
			}
			if(t>p&&g.find(t)!=g.end()){
				res2++;
			}
			fi.insert(t);
		}
		printf("%d",res);
		for(int i=p+1;i<=n;i++){
			if(g.find(i)==g.end()&&fi.find(i)==fi.end()){
				printf(" %d",i);
			}
		}
		printf("\n");
		printf("%d",res2);
		for(int i=0;i<=n;i++){
			if((i<=p||fi.find(i)!=fi.end())&&g.find(i)!=g.end()){
				printf(" %d",i);
			}
		}
		printf("\n");
	}
}