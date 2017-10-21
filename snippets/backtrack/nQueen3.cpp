#include <stdio.h>
#include <iostream>

using namespace std;

bool isSafe(int **board,int col, int row){
  for(int i=0;i<col;i++) if(board[row][i]==1) return false;
  for(int i=0;i<row;i++) if(board[i][col]==1) return false;
  for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--) if(board[i][j]==1) return false;
  for(int i=row+1,j=col-1;j>=0&&i<8;i++,j--) if(board[i][j]==1) return false;

  return true;
}

bool nQueenUtil(int **board,int col){

    if(col==8) return true;

    for(int i=0;i<8;i++){
      if(isSafe(board,col,i)){
        board[i][col]=1;
        if(nQueenUtil(board,col+1)) return true;
        board[i][col]=0;
      }
    }
    return false;
}

void nQueen(int **board){
  if(nQueenUtil(board,0)){
    for(int i=0;i<8;i++){
      for(int j=0;j<8;j++){
        printf("%3d",board[i][j]);
      }
      printf("\n");
    }
  }else{
    printf("No can do\n");
  }
}

int main(){
  int n=8;
  int **board=new int*[n];
  for(int i=0;i<8;i++) board[i]=new int[n]{0,0,0,0,0,0,0,0};

  nQueen(board);
}
