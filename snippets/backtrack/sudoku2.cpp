#include <stdio.h>
#include <iostream>

using namespace std;

void printBoard(int **board, int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      printf(" %2d",board[i][j]);
    }
    printf("\n");
  }
}

bool foundEmpty(int **board,int N, int &x,int &y){
  for(x=0;x<N;x++){
    for(y=0;y<N;y++){
      if(board[x][y]==0){
        return false;
      }
    }
  }
  return true;
}

bool isSafe(int **board, int N,int x, int y, int i){
  for(int j=0;j<N;j++){
    if(board[j][y]==i||board[x][j]==i) return false;
  }

  x=x-x%3;
  y=y-y%3;

  for(int j=0;j<3;j++){
    for(int k=0;k<3;k++){
      if(board[j+x][k+y]==i) return false;
    }
  }
  return true;
}

bool sudokuUtil(int **board, int N){
  int x=0, y=0;
  if(foundEmpty(board,N,x,y)){
    return true;
  }

  for(int i=1;i<=9;i++){
    if(isSafe(board,N,x,y,i)){
      board[x][y]=i;
      if(sudokuUtil(board,N)) return true;
      board[x][y]=0;
    }
  }
  return false;
}

void solveSudoku(int **board, int N){
  if(sudokuUtil(board,N)){
    printBoard(board,N);
  }else{
    printf("No Can Do");
  }
}

int main(){
  int N=9;
  int **board= new int*[N];
  board[0]=new int[N]{3, 0, 6, 5, 0, 8, 4, 0, 0};
  board[1]=new int[N]{5, 2, 0, 0, 0, 0, 0, 0, 0};
  board[2]=new int[N]{0, 8, 7, 0, 0, 0, 0, 3, 1};
  board[3]=new int[N]{0, 0, 3, 0, 1, 0, 0, 8, 0};
  board[4]=new int[N]{9, 0, 0, 8, 6, 3, 0, 0, 5};
  board[5]=new int[N]{0, 5, 0, 0, 9, 0, 6, 0, 0};
  board[6]=new int[N]{1, 3, 0, 0, 0, 0, 2, 5, 0};
  board[7]=new int[N]{0, 0, 0, 0, 0, 0, 0, 7, 4};
  board[8]=new int[N]{0, 0, 5, 2, 0, 6, 3, 0, 0};
  solveSudoku(board,N);
  return 0;
}
