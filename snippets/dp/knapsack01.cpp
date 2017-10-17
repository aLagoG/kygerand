#include <iostream>
#include <stdio.h>

using namespace std;

int max(int a, int b){
  return (a>b)?a:b;
}

int knapSack(int W, int wt[], int val[],int n){
  int dp[n+1][W+1];

  for(int i=0;i<n+1;i++){
    for(int j=0;j<W+1;j++){
      if(i==0||j==0){
        dp[i][j]=0;
      }else if(wt[i-1]<=j){  //When the corresponding weight is above the least amount, get the top value
        dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
      }else{
        dp[i][j]=dp[i-1][j];
      }
    }
  }
  return dp[n][W];
}

int main(){
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    printf("%d\n", knapSack(W, wt, val, n));
    return 0;
}
