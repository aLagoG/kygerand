#include <iostream>
#include <vector>

using namespace std;

//Largest Sum Contiguous Kadane

int kadane( int arr[], int n){
  int total_max=arr[0],current_max=arr[0];  //total_max and current_max starts as the first index
  int start=0,fin_s=0,fin_end=0;  //All indexes start at 1
  for(int i=1;i<n;i++){ //Starts at 1 because we already took into account arr[0]
    current_max+=arr[i];  //We update current_max to check
    if(current_max<arr[i]){ //If current_max<arr[i] all the previous becomes useless
      current_max=arr[i]; //Current_max becomes the new value since its bigger than previous sums
      start=i;  //Since new block begins, start also begins
    }
    if(current_max>total_max){  //We check if the current block has the biggest sums
      total_max=current_max;  //If it is, total sum becomes the current sum
      fin_s=start;  //We save independently the start index and finish index
      fin_end=i;
    }
  }
  cout<<"Start index: "<<fin_s<<" \nFinish index: "<<fin_end<<endl; //We print the start index and finish index (inclusive)
  return total_max; //Returns the biggest sum
}

int main(){
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = kadane(a, n);
    cout << "Maximum contiguous sum is " << max_sum<<endl;
    return 0;
}
