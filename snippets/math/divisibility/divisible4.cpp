#include <iostream>
#include <stdio.h>
#include <string>
//Divisible if last 2 numbers are divisible by 4
//Divisible if If the tens digit is even, the ones digit must be 0, 4, or 8. If the tens digit is odd, the ones digit must be 2 or 6.
//Twice the tens digit, plus the ones digit is divisible by 4

using namespace std;

bool check4(string str){
  int n=str.length();
  if(n<2) return (str[0]-'0')%4==0;
  return (((str[n-2]-'0')*10)+(str[n-1]-'0'))%4==0;
}

int main(){
    string str = "9";
    check4(str)?  cout << "Yes"<<endl : cout << "No "<<endl;
    return 0;
}
