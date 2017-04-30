#include <iostream>
using namespace std;

int t, n, flipped, one;

int nxt(int i){return i == n-1 ? 0 : i+1;}

int prev(int i){return i == 0 ? n-1 : i-1;}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int line[1001];

	scanf("%d", &t);
	while(t--){
		flipped = 0;
		one = 0;
		cin >> n;
		for(int i = 0; i < n; i++) cin >> line[i];
		for(int i = 0; i < n; i++){
			if (line[i] == 1){
				if (line[prev(i)] == 2){
					one = prev(i);
				}else if (line[nxt(i)] == n){
					one = nxt(i);
				}else{
					one = i;
				}
			}
		}
		int i = one;
		int tr = 1;
		while(1){
			if(line[i] != tr) flipped += 1;
			i = nxt(i);
			tr += 1;
			if(i == one) break;
		}
		cout << flipped << "\n";
	}
}