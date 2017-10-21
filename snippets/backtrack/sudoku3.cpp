#include <iostream>
#include <stdio.h>

using namespace std;

void printBoard(int **board){
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++){
      printf("%3d",board[i][j]);
    }
    printf("\n");
  }
}

bool isSolved(int **board,int &row,int &col){
  for(row=0;row<9;row++){
    for(col=0;col<9;col++){
      if(board[row][col]==0) return false;
    }
  }
  return true;
}

bool isSafe(int **board, int row, int col,int x){
  for(int i=0;i<9;i++) if(board[i][col]==x||board[row][i]==x) return false;

  row=row-row%3;
  col=col-col%3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(board[i+row][j+col]==x) return false;
    }
  }
  return true;
}

bool sudokuUtil(int **board){
  int row,col;
  if(isSolved(board,row,col)) return true;

  for(int i=1;i<=9;i++){
    if(isSafe(board,row,col,i)){
      board[row][col]=i;
      if(sudokuUtil(board))return true;
      board[row][col]=0;
    }
  }
  return false;
}

void sudoku(int **board){
  if(sudokuUtil(board)) printBoard(board);
  else printf("No can do homey\n");
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

  sudoku(board);


}
