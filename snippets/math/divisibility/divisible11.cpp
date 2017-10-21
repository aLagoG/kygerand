#include <iostream>
#include <stdio.h>
#include <string>
//A number is multiple of 11 if the difference of sum of odd places and sum of even places is divisible by 11

using namespace std;

bool check11(string str){
  int n=str.length();
  int odd=0,even=0;
  for(int i=0;i<n;i++){
    if(i%2){
      even+=(str[i]-'0');
    }else{
      odd+=(str[i]-'0');
    }
  }
  return (odd-even)%11==0;
}

int main(){
    string str = "1024";
    check11(str)?  cout << "Yes"<<endl : cout << "No "<<endl;
    return 0;
}
