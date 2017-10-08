#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Edit Distance O(n*m)
//RETURNS OPERATION COUNT

int min(int a, int b,int c){
    return (a<=b&&a<=c)?a:(b<=c&&b<=a)?b:c;
}

int editDistance(string str1, string str2) {

    int m=str1.length();
    int n=str2.length();
    //Create the matrix with lengthxlength
    int dp[m+1][n+1];

    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++){
        for (int j=0; j<=n; j++){
            if (i==0){// If first string is empty, only option is to insert all characters of second string
              dp[i][j] = j;  // Min. operations = j (length string2 until point j)
            }else if (j==0){ // If second string is empty, only option is to remove all characters of second string
              dp[i][j] = i; // Min. operations = i (length string1 until point i)
            }else if (str1[i-1] == str2[j-1]){  // If last characters are same, ignore last char and recur for remaining string
              dp[i][j] = dp[i-1][j-1];
            }else{ // If last character are different, consider all possibilities and find minimum
              dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                 dp[i-1][j],  // Remove
                                 dp[i-1][j-1]); // Replace
            }
        }
    }
    return dp[m][n];
}

int main(){
    string str1 = "sunday";
    string str2 = "saturday";
    printf("%d\n",editDistance(str1, str2));
    return 0;
}
