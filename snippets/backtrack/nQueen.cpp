#include <iostream>
#include <vector>
#define N 30

using namespace std;

//n Queen Problem O(n!)
//RETURNS THE BOARD

void printSolution(int board[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf(" %d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col){
    int i, j;

    for (i = 0; i < col; i++){  //Check for each column until current column if the row has a 1
      if (board[row][i]){
        return false; //If found, then return false
      }
    }

    for (i=row, j=col; i>=0 && j>=0; i--, j--){ //Check for diagonally up towards the left see if a queen is there
      if (board[i][j]){
        return false; //If found, then return false
      }
    }

    for (i=row, j=col; j>=0 && i<N; i++, j--){  //Check for diagonally down towards the left see if a queen is there
      if (board[i][j]){
        return false; //If found, then return false
      }
    }

    return true;  //Return true if you dont find anything
}

bool nQueenUtil(int board[N][N],int col){
  if(col>=N){
    return true;  //If it reaches the end and finds a nQueenUtil in the end
  }
  for(int i=0;i<N;i++){ //For each index in the column
    if(isSafe(board,i,col)){  //If the index is safe
      board[i][col]=1;  //Place the Queen in index i and column
      if(nQueenUtil(board, col+1)){  //If the next column can be accomodated too... Till the end
        return true;
      }
      board[i][col]=0;  //We can not use this because it did not return true, return back to former
    }
  }
  return false; //If it goes through the whole column and can not locate, return false
}

bool solve(){
    int board[N][N];

    //Fill in the board with 0's
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        board[i][j]=0;
      }
    }

    if (!nQueenUtil(board, 0)){ //It gives an empty board and starts from column 0
      printf("Solution does not exist\n");  //If it returns false, then it does not exist
      return false;
    }

    printSolution(board); //Else, it prints the board
    return true;
}

int main(){
    solve();
    return 0;
}
