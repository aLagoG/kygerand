//3468
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> mp;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	while(n--){
		string line;
		cin >> line;
		sort(line.begin(),line.end());
		if(mp.find(line)==mp.end()){
			mp.insert(make_pair(line,0));
		}else{
			mp[line]++;
		}
		cout << mp[line] << "\n";
	}
}