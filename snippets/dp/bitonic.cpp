#include <iostream>
#include <vector>

using namespace std;

//Longest Bitonic Subsequence O(n^2)
//RETURNS JUST THE LENGTH

int bitonic(int arr[],int n){

  int lis[n];
  int lds[n];
  //Base case for LIS and LDS, LDS starts at 0 because it adds up and from that start space, itself doesnt count.
  for(int i=0;i<n;i++) lis[i]=1;
  for(int i=0;i<n;i++) lds[i]=0;

  //Typical LIS
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(arr[j]<=arr[i] && lis[j]+1>lis[i]){
        lis[i]=lis[j]+1;
      }
    }
  }

  //Typical LDS
  for (int i=n-2; i>=0; i--){
    for (int j=n-1; j>i; j--){
      if(arr[i] >arr[j] && lds[i] < lds[j] + 1){
        lds[i]=lds[j]+1;
      }
    }
  }

  //Find max after adding the two values
  int max=lis[0]+lds[0];
  for(int i=1;i<n;i++){
    if(lis[i]+lds[i]>max){
      max=lis[i]+lds[i];
    }
  }
  return max;
}

int main(){
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of Longest Bitonic Subsequence is %d\n", bitonic( arr, n ) );
  return 0;
}
