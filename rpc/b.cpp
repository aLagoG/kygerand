#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


int main(){
  int n;
  scanf("%d",&n);

  vector<int> pirates(n);
  vector<int> chests(n);

  int x;
  for(int i=0;i<n;i++){
    scanf("%d",&x);
    pirates[i]=x;
  }
  for(int i=0;i<n;i++){
    scanf("%d",&x);
    chests[i]=x;
  }

  sort(pirates.begin(),pirates.end());
  sort(chests.begin(),chests.end());

  int tot=1;
  int count;
  for(int i=0;i<n;i++){

    count=upper_bound(pirates.begin()+i,pirates.end(),chests[i])-pirates.begin()-i;

    if(count==0){
      tot=0;
      break;
    }else{
      tot*=count;
      tot%=1000000007;
    }
    // printf("%d\n",tot);
  }

  printf("%d\n",tot);
  return 0;
}
