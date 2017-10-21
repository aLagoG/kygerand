#include <stdio.h>
#include <iostream>
#define N 4

using namespace std;

void printSolution(int sol[N][N]){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            printf(" %d ", sol[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int maze[N][N],int x, int y){
  if(x>=N||y>=N){ //If outside of the maze
    return false;
  }
  if(maze[x][y]==0){
    return false;
  }
  return true;
}

bool solveMazeUtil(int maze[N][N],int finMaze[N][N],int x, int y){
  if(x==N-1&&y==N-1){ //Gets to destination
    finMaze[N-1][N-1]=1;
    return true;
  }


  if(isSafe(maze,x,y)){
    finMaze[x][y]=1;
    if(solveMazeUtil(maze,finMaze,x+1,y)){
      return true;
    }
    if(solveMazeUtil(maze,finMaze,x,y+1)){
      return true;
    }
    finMaze[x][y]=0;
    return false;
  }
  return false;
}

bool solveMaze(int maze[N][N]){
  int finMaze[N][N];  //Create final solution board
  for(int i=0;i<N;i++){ //Initialize the board with 0s
    for(int j=0;j<N;j++){
      finMaze[i][j]=0;
    }
  }

  if(solveMazeUtil(maze,finMaze,0,0)){
    printSolution(finMaze);
  }else{
    printf("Maze can not be solved");
  }
return true;
}

int main(){
    int maze[N][N]  =
      { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    solveMaze(maze);
    return 0;
}
