#include <stdio.h>
#include <iostream>

using namespace std;

void printArray(int perm[],int N){
  for(int i=0;i<N;i++)printf("%3d",perm[i]);
  printf("\n");
}

void AlexanderBogomolyn(int perm[],int N, int k){
  static int level= -1;
  level=level+1;
  perm[k]=level;
  if(level==N) printArray(perm,N);
  else{
    for(int i=0;i<N;i++){
      if(perm[i]==0){
        AlexanderBogomolyn(perm,N,i);
      }
    }
  }
  level--;
  perm[k]=0;
}

int main(){
    int N = 3;
    int perm[N];
    AlexanderBogomolyn(perm, N, 0);
    return 0;
}
