#include <iostream>
#include <vector>

using namespace std;

//Longest Common Subsequence
//RETURNS JUST THE LENGTH

int max(int a, int b){
    return (a > b)? a : b;
}

int lcs( char *X, char *Y){
   int m = strlen(X);
   int n = strlen(Y);
   //m+1 and n+1 because we need base cases where we compare empty string with empty string
   int L[m+1][n+1];
   int i, j;

   //Base case where if given abcdaf and acbcf, we give value 0 to when strings are empty
   for(i=0;i<m;i++){
     L[i][0]=0;
   }

   for(i=0;i<n;i++){
     L[0][i]=0;
   }

   for (i=1; i<=m; i++){  //Goes from 1 to m because 0 is empty string
     for (j=1; j<=n; j++){  //Same as above
       if (X[i-1] == Y[j-1]){ //You check the value at index i-1 and j-1 because 0 is empty string
         //If the values are the same, you add 1 of length to L[i-1][j-1]
         //since L[i-1][j-1] is the LCS of the 2 strings before the coinciding values
         L[i][j] = L[i-1][j-1] + 1;
       }else {
         //Else, you get the maximum of LCS of above or to the left
         L[i][j] = max(L[i-1][j], L[i][j-1]);
       }
     }
   }
   return L[m][n];
}

int main(){
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";

  printf("Length of LCS is %d\n", lcs(X, Y) );
  return 0;
}
