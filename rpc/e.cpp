#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int arr[3];
  scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
  sort(arr,arr+3);

  // int opp[3];
  // bool found=0;
  // int count=0;
  // for(int i=1;i<=7 && count<3;i++){
  //   found=0;
  //   for(int j=0;j<3;j++){
  //     if(arr[j]==i) found=1;
  //   }
  //   if(!found) opp[count++]=i;
  // }

  // printf("opp[]:\n");
  // printf("%d %d %d\n",opp[0],opp[1],opp[2]);
  //
  // printf("arr[]:\n");
  // printf("%d %d %d\n",arr[0],arr[1],arr[2]);



  if((arr[0]==1&&arr[1]==2)||(arr[0]==1&&arr[1]==3)){
    printf("S\n");
  }else if(arr[0]==1&&arr[1]==4&&arr[2]==5){
    printf("S\n");
  }else if(arr[0]==2&&arr[1]==3&&arr[2]==4){
    printf("S\n");
  }else{
    printf("N\n");
  }


  return 0;
}
