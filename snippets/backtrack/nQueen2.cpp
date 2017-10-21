#include <stdio.h>
#include <iostream>

using namespace std;

void printBoard(int **board,int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf(" %2d",board[i][j]);
    }
    printf("\n");
  }
}

bool isSafe(int **board,int N,int row, int col){
  for(int i=col-1;i>=0;i--){
    if(board[row][i]) return false;
  }
  for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
    if(board[i][j]) return false;
  }
  for(int i=row+1,j=col-1;i<N&&j>=0;i++,j--){
    if(board[i][j]) return false;
  }
  return true;
}

bool nQueenUtil(int **board,int N, int col){
  if(N==col) return true;

  for(int row=0;row<N;row++){
    if(isSafe(board,N,row,col)){
      board[row][col]=1;
      if(nQueenUtil(board,N,col+1)) return true;
      board[row][col]=0;
    }
  }
  return false;
}

void solvenQueen(int N){
  int **board= new int*[N];
  for(int i=0;i<N;i++){
    board[i]=new int[N];
  }

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      board[i][j]=0;
    }
  }

  if(nQueenUtil(board,N,0)){
    printBoard(board,N);
  }else{
    printf("No Can Do\n");
  }
}

int main(){
  solvenQueen(8);
  return 0;
}
