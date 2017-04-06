#include <iostream>
#include <string.h>

using namespace std;

bool dp[2001][2001];
int cumul[2001];
int counts[2001];
int after[2001];

inline bool isPalindrome(string s, int a, int b){
    if(a==b){
        return true;
    }
    while(a<b){
        if(s[a++]!=s[b--]){
            return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    memset(counts,0,sizeof counts);
    memset(after,0,sizeof after);
    memset(cumul,0,sizeof cumul);
    string line;
    cin >> line;
    int n = line.length();
    int total = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            dp[i][j] = isPalindrome(line,i,j);
            if(dp[i][j]){
                cumul[j]++;
                counts[j]++;
                if(i!=j){
                    after[i]++;
                }
                total++;
            }
        }
        for(int j=i-1;j>=0;j--){
            if(dp[j][i]){
                after[i]--;
            }
        }
        cumul[i+1]+=cumul[i];
        after[i+1]+=after[i];
    }
    unsigned long res = 0;
    for(int i=0;i<n;i++){
        res += counts[i]*(total-cumul[i]-after[i]);
    }
    cout << res << endl;
}