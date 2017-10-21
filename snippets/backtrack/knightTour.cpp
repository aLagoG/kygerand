#include <stdio.h>
#include <iostream>
#define N 8

using namespace std;

void printSolution(int sol[N][N]){
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            printf(" %2d ", sol[x][y]);
          }
        printf("\n");
    }
}

bool isSafe(int board[N][N],int x, int y){
  if(x>=N||x<0||y>=N||y<0){ //If it goes out of the board return false
    return false;
  }
  if(board[x][y]!= -1){  //If it is occupied return false
    return false;
  }
  return true;
}

bool solveKnightUtil(int board[N][N], int currX, int currY, int currMove, int x[N],int y[N]){
  if(currMove==N*N){ //If it overpasses the amount of moves, then return false
    return true;
  }

  int nextX;
  int nextY;

  for(int i=0;i<8;i++){ //Goes through all possibilities
    nextX=currX+x[i]; //Calculates the next x value
    nextY=currY+y[i]; //Calculates the next y value
    if(isSafe(board,nextX,nextY)){  //If the next value is safe
      board[nextX][nextY]=currMove; //Change the next values to the current Move
      if(solveKnightUtil(board,nextX,nextY,currMove+1,x,y)){  //If recursion takes to the end, it returns true
        return true;
      }else{
        board[nextX][nextY]= -1;  //If it does not go to the end, it returns to -1
      }
    }
  }

  return false; //If it goes through all the possibilities and it still can not find, it's impossible, return false
  //Backtrack
}


bool solveKnight(){
  int board[N][N];  //Create a board with NxN

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      board[i][j]= -1; //Assign -1 to the whole board
    }
  }

  board[0][0]=0;  //Starts at board[0][0] therefore, its turn is 0

  // int x[8]={2,2,-2,-2,1,1,-1,-1}; //All possible moves that a piece can make
  // int y[8]={-1,1,-1,1,2,-2,2,-2};

  int x[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
  int y[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };

  if(solveKnightUtil(board,0,0,1,x,y)){ //If it can solve itself with solveKnightUtil, then it prints the solution
    printSolution(board);
  }else{
    printf("Does not have any solutions\n");  //Else, prints it can not be accomplished
  }

  return true;
}


int main(){
    solveKnight();
    return 0;
}
