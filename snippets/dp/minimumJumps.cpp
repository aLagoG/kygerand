#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int minJumps(int arr[],int n){
  int dp[n];
  dp[0]=0;

  for(int i=1;i<n;i++){
    dp[i]=INT_MAX-1;
    for(int j=0;j<i;j++){
      if(arr[j]+j>=i&&dp[j]+1<dp[i]){
        dp[i]=dp[j]+1;
      }
    }
  }
  return dp[n-1]==INT_MAX-1?-1:dp[n-1];
}

int main(){
  int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d\n", minJumps(arr,n));
  return 0;
}
