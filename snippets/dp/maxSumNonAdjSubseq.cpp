#include <iostream>
#include <stdio.h>

using namespace std;

int max(int a, int b){
  return a>b?a:b;
}

int FindMaxSum(int arr[],int n){
  int exclusive=0;  //Exclusive starts at 0 because at arr[1], we musn't take into account arr[0]
  int inclusive=arr[0]; //Inclusive starts at arr[0]
  int newex=0;  //Just a placeholder
  for(int i=1;i<n;i++){
    newex=inclusive;  //Save the old inclusive for exclusive
    inclusive=max(inclusive,exclusive+arr[i]);  //New inclusive will be the max of current high, and to see if new high
    exclusive=newex;  //Exclusive will be the past high which is high until i-1
  }
  return inclusive; //Return inclusive because it is the highest at point N-1
}

int main(){
  int arr[] = {5, 5, 10, 100, 10, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("%d\n", FindMaxSum(arr, n));
  return 0;
}
