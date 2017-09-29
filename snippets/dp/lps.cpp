#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Longest Palindromic Subsequence O(n^2)

int max(int a, int b){
    return a>b?a:b;
}

int lps(char *s) {
    int arr[strlen(s)][strlen(s)];
    for(int i=0;i<strlen(s);i++){
        arr[i][i]=1;
    }

    for(int l=2;l<=strlen(s);l++){
        for(int i=0;i<strlen(s)-1;i++){
            int j=i+l-1;
  	        if(l==2 && s[i]==s[j]){
                  arr[i][j]=2;
              }else if(s[i]==s[j]){
                  arr[i][j]=arr[i+1][j-1]+2;
              }else{
                  arr[i][j]=max(arr[i][j-1],arr[i+1][j]);
              }
        }
    }
    return arr[0][strlen(s)-1];
}

int main(){
    char seq[] = "alaaabaaabbbbaaaa";
    int n = strlen(seq);
    printf ("The length of the LPS is %d\n", lps(seq));
    return 0;
}
