#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
  //GIVEN THAT L is DP already done
  char lcs[index+1];
  lcs[index] = '\0'; // Set the terminating character

  // Start from the right-most-bottom-most corner and
  // one by one store characters in lcs[]
  int i = m, j = n;
  while (i > 0 && j > 0){
     // If current character in X[] and Y are same, then
     // current character is part of LCS
     if (X[i-1] == Y[j-1]){
         lcs[index-1] = X[i-1]; // Put current character in result
         i--; j--; index--;     // reduce values of i, j and index
     }

     // If not same, then find the larger of two and
     // go in the direction of larger value
     else if (L[i-1][j] > L[i][j-1]){
       i--;
     }
     else{
        j--;
     }
  }
  // Print the lcs
  cout << "LCS of " << X << " and " << Y << " is " << lcs;
}
