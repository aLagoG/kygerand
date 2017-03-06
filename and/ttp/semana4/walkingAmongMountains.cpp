//2227
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef unsigned long long ul;

char mp[10][10];
typedef pair<int, int> pii;
typedef pair<int, pii> pip;
priority_queue<pip, vector<pip>, greater<pip>> q;
int x,y;

ul search(){
	q.push(pip(0,pii(0,0)));
	ul tmp;
	while(!q.empty()){
		pip node = q.top();
		q.pop();
		if(node.second.second==x&&node.second.first==y){
			return node.first;
		}
		if(node.second.second<x){
			tmp = max(0,mp[node.second.first][node.second.second+1]-mp[node.second.first][node.second.second]);
			node.second.second++;
			node.first += tmp;
			q.push(node);
			node.second.second--;
			node.first -= tmp;
		}
		if(node.second.first<y){
			tmp = max(0,mp[node.second.first+1][node.second.second]-mp[node.second.first][node.second.second]);
			node.second.first++;
			node.first += tmp;
			q.push(node);
			node.second.first--;
			node.first -= tmp;
		}
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
	printf("%llu\n",search());
}