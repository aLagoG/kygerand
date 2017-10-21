#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//Longest Repeating Subsequence
//A simple variation from Longest Common Subsequence (LCS)

int max(int a, int b){
  return a>b?a:b;
}

string lrs(string str){
  int n=str.length();
  int dp[n+1][n+1];

  for(int i=0;i<=n;i++){
    dp[0][i]=0;
    dp[i][0]=0;
  }

  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(str[i-1]==str[j-1]&& i!=j){
        dp[i][j]=dp[i-1][j-1]+1;
      }else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[n][n];
}

int main(){
    string str = "AABEBCDD";
    cout << lrs(str)<<endl;
    return 0;
}
