#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001
#define max(x,y) (x>y?x:y)

string a;
string b;

vector<vector<int>> dp(MAX, vector<int>(MAX));

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	while(cin >> a >> b){
		cout << a << ' ' << b << '\n';
		int n=a.length(), m=b.length();
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i-1]==b[j-1]){
					dp[i][j] = dp[i-1][j-1]+1;
				}else{
					dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
				}
			}
		}
		cout << dp[n][m] << '\n';
	}
}