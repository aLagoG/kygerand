#include <stdio.h>
#include <iostream>
#define N 9

using namespace std;

bool isDone(int board[N][N],int &row,int &col){  //Go through the board to see if it is full
  for(row=0;row<N;row++){ //Row and Col saves itself while iterating to stop when it is 0
    for(col=0;col<N;col++){
      if(board[row][col]==0){
        return false; //Returns -1 if it finds a 0
      }
    }
  }
  return true; //Returns 1 if it is done (has no 0s)
}

bool isSafe(int board[N][N],int row, int col, int num){
  for(int i=0;i<N;i++){ //Check if num has been used in row or column
    if((board[i][col]==num)||(board[row][i]==num)){
      return false;
    }
  }
  row=row-row%3;
  col=col-col%3;
  for(int i=0;i<3;i++){ //Check if num is found in the box
    for(int j=0;j<3;j++){
      if(board[row+i][col+j]==num){
        return false;
      }
    }
  }

  return true;
}

bool solveSudoku(int board[N][N]){
  int row=0,col=0;  //Initialize row and col to move it around
  if(isDone(board,row,col)){  //isDOne will change row and col to where board[][]==0
    return true;
  }

  for(int i=1;i<=9;i++){
    if(isSafe(board, row, col, i)){ //Send board, row, col, and number to see if number can fit there
      board[row][col]=i;  //If it can fit there, save value there

      if(solveSudoku(board)){ //And finally, check if the board can be completed with further numbers
        return true;
      }

      board[row][col]=0;  //If it can not be completed with guesses, then it saves it to 0 to try it with next number in for
    }
  }

  return false; //Returns false if it can not be completed to trigger backtrack
}

void printBoard(int board[N][N]){
    for (int row = 0; row < N; row++){
       for (int col = 0; col < N; col++){
             printf("%2d", board[row][col]);
        }
        printf("\n");
    }
}

int main(){
  int board[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                    {5, 2, 0, 0, 0, 0, 0, 0, 0},
                    {0, 8, 7, 0, 0, 0, 0, 3, 1},
                    {0, 0, 3, 0, 1, 0, 0, 8, 0},
                    {9, 0, 0, 8, 6, 3, 0, 0, 5},
                    {0, 5, 0, 0, 9, 0, 6, 0, 0},
                    {1, 3, 0, 0, 0, 0, 2, 5, 0},
                    {0, 0, 0, 0, 0, 0, 0, 7, 4},
                    {0, 0, 5, 2, 0, 6, 3, 0, 0}};
  if (solveSudoku(board) == true){
        printBoard(board);
  }else{
       printf("No solution exists");
  }
  return 0;
}
