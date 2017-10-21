#include <stdio.h>
#include <iostream>

using namespace std;

bool isSolvable(int puzzle[]){
  int inv=0;
  for(int i=0;i<9;i++){
    for(int j=i+1;j<9;j++){
      if((puzzle[i]&&puzzle[j])&&(puzzle[i]>puzzle[j])) inv++;
    }
  }
  if(inv%2) return false;
  return true;
}

int main(){

  int **puzzle= new int*[3];
  puzzle[0]=new int[3]{1,8,2};
  puzzle[1]=new int[3]{0,4,3};
  puzzle[2]=new int[3]{7,6,5};

  isSolvable((int *)puzzle)? cout << "Solvable"<<endl:
                      cout << "Not Solvable"<<endl;
  return 0;
}
