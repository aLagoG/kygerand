// #include <stdio.h>
#include <iostream>

using namespace std;

#define N 3010
#define L 2000

typedef unsigned long long llu;

string names[N];
llu freq[N][2];

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	llu t;
	// scanf("%llu",&t);
	cin >> t;
	while(t--){
		int n,k;
		// scanf("%d %d",&n,&k);
		cin >> n >> k;
		for(int i=0;i<n;i++){
			// scanf("%s %llu",names[i],&freq[i][0]);
			cin >> names[i] >> freq[i][0];
			freq[i][1] = freq[i][0];	
		}
		while(k--){
			int idx = 0;
			llu min = 1l<<62;
			for(int i=0;i<n;i++){
				if(freq[i][1]<min){
					min = freq[i][1];
					idx = i;
				}
			}
			// printf("%llu %s\n",freq[idx][1],names[idx]);
			cout << freq[idx][1] << ' ' << names[idx] << '\n';
			freq[idx][1] += freq[idx][0];
		}
	}
}