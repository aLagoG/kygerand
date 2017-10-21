#include <stdio.h>
#include <iostream>

using namespace std;

int max(int a, int b){
  return (a<b)b:a;
}

int minJumpsn(int arr[],int n){

  if(n<=1) return 0;  //If array is empty, return 0
  if(arr[0]==0) return -1; //If it can not get out of first index, return -1

  int maxReach=arr[0];  //MaxReach starts as first available option
  int step=arr[0];  //Amount of steps you may take is first available option
  int jumps=1;  //The jump it takes to get to MaxReach

  for(int i=1;i<n;i++){ //Goes through the array
    if(i==n-1) return jumps;  //Returns the least jumps to get to n-1

    maxReach=max(maxReach,i+arr[i]);  //Check if the new arr[] index reaches a new max

    step--; //You use a step to get to this index;

    if(step==0){  //If you reach the end of your steps with with and you have no steps left
      jump++; //Increase jump because a new jump is needed

      if(i >= maxReach){  //If you exceed your maxReach, it is because you can not reach it
        return -1;  //Return -1
      }
      step = maxReach - i;  //
    }
  }

}

int main(){
  int arr[] = {1, 3, 6, 3, 2, 3, 6, 8, 9, 5};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Minimum number of jumps to reach end is %d\n", minJumpsn(arr,n));
  return 0;
}
