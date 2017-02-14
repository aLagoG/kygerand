//1167
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int din[16][1<<17-1];

int game(string arr[], int len, int idx, int mask){
	if(mask==1<<len-1){
		return arr[idx].size();
	}
	int max = 0;
	for(int i=0;i<len;i++){
		if(mask&1<<i || arr[idx].back() != arr[i].front()){
			continue;
		}
		int val;
		if(din[i][mask|1<<i]){
			val = din[i][mask|1<<i];
		}else{
			val =  game(arr,len,i,mask|1<<i);
			din[i][mask|1<<i] = val;
		}
		if(val>max){
			max = val;
		}
	}
	return max + arr[idx].size();
}

int main(){
		ios_base::sync_with_stdio(false);
		int t;
		//scanf("%d", &t);
		cin >> t;
		while(t--){
			int n;
			memset(din, 0, sizeof din);
			//scanf("%d", &n);
			cin >> n;
			string words[n];
			for(int i=0;i<n;i++){
				//scanf("%s", &words[i]);
				cin >> words[i];
			}
			int com = 0;
			for(int i=0;i<n;i++){
				int val = game(words, n, i, 1<<i);
				//cout << val << "-\n";
				if(val>com){
					com = val;
				}
			}
			cout << com << "\n";
		}
}
