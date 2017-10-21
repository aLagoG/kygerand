#include <stdio.h>
#include <iostream>
#define V 5

using namespace std;

void printSolution(int path[]){
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++){
        printf(" %d ", path[i]);
    }

    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}

bool hamCycleUtil(bool graph[V][V],int arr[V],int x){
  if(x==V){
    return true;
  }

  for(int i=0;i<V;i++){
    if(graph[x][i]!=0&&i!=x){  //If it is not safe,
      arr[x]=i;
      if(hamCycleUtil(graph,arr,x+1)){
        return true;
      }
      arr[x]=-1;
    }
  }
  return false;
}

bool hamCycle(bool graph[V][V]){
  int arr[V];
  for(int i=0;i<V;i++){
    arr[i]=-1;
  }

  if(hamCycleUtil(graph,arr,0)){
    printSolution(arr);
  }else{
    printf("Has no solution\n");
  }

  return true;
}

int main(){
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                      };
    hamCycle(graph1); //Print the solution

   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                      };

    hamCycle(graph2); // Print the solution

    return 0;
}
