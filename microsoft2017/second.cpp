#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main(){
  int n;
  int idk;
  scanf("%d",&n);
  scanf("%d",&idk);
  int arr[n];
  int index;
  int max=0;
  int min=10000000;
  int tot=0;
  int sum=0;
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    tot+=arr[i];
    if(arr[i]>max)index=i;
    if(arr[i]<min) min=arr[i];
    sum+=arr[i];
  }
  sum-=arr[n-1];
  min*=idk;
  min+=sum;
  printf("%d",min);

  // int count=0;
  // int sum=0;
  // max=arr[index];
  // for(int i=0;i<n;i++){
  //   if(arr[i]+sum>max){
  //     count++;
  //     sum=arr[i];
  //   }else if(arr[i]+sum==max){
  //     count++;
  //     sum=0;
  //   }else{
  //     sum+=arr[i];
  //   }
  // }
  // if(sum!=0) count++;
  //
  // if(sum!=0) count++;
  // printf("%d",count+1);
  return 0;
}
