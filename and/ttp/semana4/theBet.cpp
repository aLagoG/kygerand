//3352
#include <iostream>
#include <vector>
#include <array>

using namespace std;

string line;
string word;
vector<array<int,2>> dp;
int res=0;
int nw,nl;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> line >> word;
	nl = line.length();
	nw = word.length();
	int off = 0;
	for(int i=0;i<nl;i++){
		for(int j=off;j<dp.size();j++){
			if(line[i]==word[++dp[j][1]]){
				if(dp[j][1]==nw-1){
					off++;
				}
			}else{
				dp.erase(dp.begin()+j);
			}
		}
		if(line[i]==word[0]){
			dp.push_back({i,0});
		}
	}
	while(dp.back()[1]!=nw-1){
		dp.pop_back();
	}
	vector<int> cnt(dp.size(),0);
	int siz = dp.size()-1;
	for(int i=0;i<siz;i++){
		int idx = dp[i][0]+nw;
		for(int j=i+1;j<=siz;j++){
			if(idx>dp[j][0]){
				cnt[i]++;
				cnt[j]++;
			}
		}
	}
	array<int,2> last = dp[0];
	res++;
	for(int i=1;i<=siz;i++){
		if(dp[i][0]>last[0]+nw){
			res++;
			last = dp[i];
		}
		if(cnt[i]>cnt[last[0]]){
			last = dp[i];
		}
	}
	cout << res << '\n';
}