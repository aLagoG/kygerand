#include <iostream>
#include <vector>

using namespace std;

int coverDistance(int d){
  int count[d+1];
  count[0]=1; //Base case where to get to 0, it's only 1 option
  count[1]=1; //Base case where to get to step 1, you can only take the 1 step option
  count[2]=2; //Base case where to get to step 2, you can either take 2 1's or 1 2's.
  for(int i=3;i<=d;i++){
    //If you want to reach i, you can reach i from either i-1, i-2, and i-3 steps. Therefore you add all possibilities
    count[i]=count[i-1]+count[i-2]+count[i-3];  //Becuase you can only take 1, 2 or 3 steps.
  }
  return count[d];
}

int main(){
    int dist = 4;
    cout << coverDistance(dist)<<endl;
    return 0;
}
