#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int minJumps(int arr[],int n){
  int dp[n];
  dp[0]=0;

  for(int i=1;i<n;i++){ //Iterate through all, to check with each place
    dp[i]=INT_MAX-1;  //Start with INT_MAX in case you can not reach it
    for(int j=0;j<i;j++){ //Go through each element to see if you can reach arr[i] from it
      if(arr[j]+j>=i&&dp[j]+1<dp[i]){ //If you can reach and if dp[j]+1 is smaller, we change it
        dp[i]=dp[j]+1;
      }
    }
  }
  return dp[n-1]==INT_MAX-1?-1:dp[n-1]; //If the end is INT_MAX-1, it means you can not reach it
}

int main(){
  int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d\n", minJumps(arr,n));
  return 0;
}
