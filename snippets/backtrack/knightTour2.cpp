#include <stdio.h>
#include <iostream>

using namespace std;

void printBoard(int **board,int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf(" %2d ",board[i][j]);
    }
    printf("\n");
  }
}

bool isSafe(int **board,int N,int x,int y){
  if(x>=N||x<0||y>=N||y<0) return false;
  if(board[x][y]!=-1) return false;
  return true;
}

bool solveKnightUtil(int **board,int N, int x[], int y[],int level,int currX, int currY){
  if(level==N*N) return true;

  for(int i=0;i<8;i++){
    int nextX=currX+x[i];
    int nextY=currY+y[i];
    if(isSafe(board,N,nextX,nextY)){
      board[nextX][nextY]=level;
      if(solveKnightUtil(board,N, x,y,level+1,nextX,nextY)) return true;
      board[nextX][nextY]=-1;
    }
  }
  return false;
}

void solveKnight(int N){
  int **board=new int*[N];  //Create the board

  for(int i=0;i<N;i++){
    board[i]=new int[N];
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      board[i][j]=-1;
    }
  }

  board[0][0]=0;

  int x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
  int y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

  if(solveKnightUtil(board,N,x,y,1,0,0)){
    printBoard(board,N);
  }else{
    printf("No Can Do\n");
  }
}

int main(){
    solveKnight(8);
    return 0;
}
