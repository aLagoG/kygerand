//3740
// #include <stdio.h>
#include <iostream>

#define next(i) (i==n-1?0:i+1)
#define prev(i) (i==0?n-1:i-1)

using namespace std;

int circ[1001];
int n;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	// scanf("%d",&t);
	while(t--){
		// scanf("%d",&n);
		cin >> n;
		int ini;
		for(int i=0;i<n;i++){
			// scanf("%d",&circ[i]);
			cin >> circ[i];
			if(circ[i]==1){
				if(circ[prev(i)]==2){
					ini = prev(i);
				}else if(circ[next(i)]==n){
					ini = next(i);
				}else{
					ini = i;
				}
			}
		}
		int i=ini;
		int v = 1;
		int cnt = 0;
		do{
			// printf("%d %d %d\n",i,circ[i],v);
			if(circ[i]!=v++){
				cnt++;
			}	
			i=next(i);
		}while(i!=ini);
		// printf("%d\n",cnt);
		cout << cnt << "\n";
	}
}