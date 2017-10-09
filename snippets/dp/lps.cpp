#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Longest Palindromic Subsequence O(n^2)
//RETURNS JUST THE LENGTH

int max(int a, int b){
    return a>b?a:b;
}

int lps(char *s) {

    //Create the matrix with lengthxlength
    int arr[strlen(s)][strlen(s)];

    //Case where we contemplate string 0-0, 1-1... etc, always palindrome because 1 string.
    for(int i=0;i<strlen(s);i++){
        arr[i][i]=1;
    }

    for(int l=2;l<=strlen(s);l++){  //Length of the strings go up, start with 2: 0-2, 1-3, 2-4, 3-5... etc
        for(int i=0;i<strlen(s)-1;i++){ //Start value of 0-2, 1-3... etc
            int j=i+l-1;  //Calculate i to j for 0-2, 1-3... etc
            if (s[i] == s[j] && l == 2){  //If length is 2 and same characters, ONLY INCREMNET BY 1
              arr[i][j] = 2;
            }if(s[i]==s[j]){  //Else, ALWAYS INCREMENT BY 2 with the value diagonal, down to the left
                  arr[i][j]=arr[i+1][j-1]+2;
            }else{  //Else, MAX OF BELOW AND TO THE LEFT
                arr[i][j]=max(arr[i][j-1],arr[i+1][j]);
            }
        }
    }
    return arr[0][strlen(s)-1]; //Return the end of the first row which is the max palindromic subsequence length
}

int main(){
    // char seq[] = "alaaabaaabbbbaaaa";
    char seq[] = "agbdba";
    int n = strlen(seq);
    printf ("The length of the LPS is %d\n", lps(seq));
    return 0;
}
