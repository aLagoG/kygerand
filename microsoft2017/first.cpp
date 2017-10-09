#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Longest Palindromic Subsequence O(n^2)

int countOnes(int value){
  int count=0;
  while(value){
    value&=(value-1);
    count++;
  }
  return count;
}

int main(){
  int n;
  scanf("%d",&n);
  // char seq[] = "alaaabaaabbbbaaaa";
  // int n = strlen(seq);
  for(int i=0;i<n;i++){
    string a,b;
    cout<<"Group "<<i+1<<":"<<" ";
    cin>>a>>b;
    if(a[0]!=b[0]){
      if((a[0]=='1'&&b[0]=='2')||(a[0]=='2'&&b[0]=='1')){
        cout<<"3";
      }
      if((a[0]=='2'&&b[0]=='3')||(a[0]=='3'&&b[0]=='2')){
        cout<<"1";
      }
      if((a[0]=='1'&&b[0]=='3')||(a[0]=='3'&&b[0]=='1')){
        cout<<"2";
      }
    }else{
      cout<<a[0];
    }
    if(a[1]!=b[1]){
      if((a[1]=='E'&&b[1]=='S')||(a[1]=='S'&&b[1]=='E')){
        cout<<"F";
      }
      if((a[1]=='E'&&b[1]=='F')||(a[1]=='F'&&b[1]=='E')){
        cout<<"S";
      }
      if((a[1]=='F'&&b[1]=='S')||(a[1]=='S'&&b[1]=='F')){
        cout<<"E";
      }
    }else{
      cout<<a[1];
    }
    if(a[2]!=b[2]){
      if((a[2]=='R'&&b[2]=='P')||(a[2]=='P'&&b[2]=='R')){
        cout<<"G";
      }
      if((a[2]=='R'&&b[2]=='G')||(a[2]=='G'&&b[2]=='R')){
        cout<<'P';
      }
      if((a[2]=='P'&&b[2]=='G')||(a[2]=='G'&&b[2]=='P')){
        cout<<"R";
      }
    }else{
      cout<<a[2];
    }
    if(a[3]!=b[3]){
      if((a[3]=='O'&&b[3]=='S')||(a[3]=='S'&&b[3]=='O')){
        cout<<"D";
      }
      if((a[3]=='O'&&b[3]=='D')||(a[3]=='D'&&b[3]=='O')){
        cout<<'S';
      }
      if((a[3]=='S'&&b[3]=='D')||(a[3]=='D'&&b[3]=='S')){
        cout<<"O";
      }
    }else{
      cout<<a[3];
    }
    cout<<endl;
  }
  return 0;
}
