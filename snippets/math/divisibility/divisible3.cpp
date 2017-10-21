#include <stdio.h>
#include <iostream>
#include <string>
//A number is divisible by 3 if the sum of all digits is divisble by 3

using namespace std;

bool check3(string str){
  int n=str.length();
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=(str[i]-'0');
  }
  return (sum%3==0);
}

int main(){
    string str = "1332";
    check3(str)?  cout << "Yes"<<endl : cout << "No "<<endl;
    return 0;
}
