//2835
#include <stdio.h>
#include <vector>

typedef unsigned long long uint;

using namespace std;

vector<uint> graph[100001];
vector<uint> dp[100001];
uint lines[100000][2];

uint getChildren(uint n, uint doNot){
	uint count = 1;
	for(uint i=0;i<graph[n].size();i++){
		if(graph[n][i]==doNot){
			continue;
		}
		if(dp[n][i]==0){
			dp[n][i] = getChildren(graph[n][i],n);
		}
		count += dp[n][i];
	}
	return count;
}

inline uint searchDP(uint a, uint b){
	return getChildren(a,b)*getChildren(b,a);
}
int main(){
	int t;
	scanf("%d",&t);
	for(int i=1;i<t;i++){
		uint a, b;
		scanf("%llu %llu",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);
		dp[a].push_back(0);
		dp[b].push_back(0);
		lines[i][0] = a;
		lines[i][1] = b;
	}
	for(uint i=1;i<t;i++){
		printf("%llu\n", searchDP(lines[i][0],lines[i][1]));
		
	}
}