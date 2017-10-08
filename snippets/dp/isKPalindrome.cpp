#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

//A K-Palindrome String transforms into a Palindrome removing at most K Palindromes

//IF THE LONGEST LENGTH-LEN(LONGEST PALINDROMIC SUBSEQUENCE)>K, IT'S IMPOSSIBLE

int min(int a, int b){
  return (a<b)? a:b;
}

bool isKPal(string str, int k){
  int n=str.length();
  string str2=str;
  reverse(str2.begin(),str2.end());
  int dp[n+1][n+1];

  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      if(i==0){
        dp[i][j]=j;
      }else if(j==0){
        dp[i][j]=i;
      }else if(str[i-1]==str2[j-1]){
        dp[i][j]=dp[i-1][j-1];
      }else{
        dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
      }
    }
  }
  return dp[n][n]<k;
}

int main(){
    string str = "acdcb";
    int k = 2;
    isKPal(str, k)? cout << "Yes"<<endl : cout << "No"<<endl;
    return 0;
}
