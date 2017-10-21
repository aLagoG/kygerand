#include <string>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>

using namespace std;

void permuteUtil(int n,string str, char c[], int count[],int level, vector<string> *results){

  if(level==str.length()){
    results->push_back(str);
    return;
  }

  for(int i=0;i<n;i++){
    if(count[i]==0) continue;
    count[i]--;
    str[level]=c[i];
    permuteUtil(n,str,c,count,level+1, results);
    count[i]++;
  }

}

void permute(string str,vector<string> *results){
  map<char,int> mp;
  for(int i=0;i<str.length();i++){
    if(mp.find(str[i])==mp.end()){
      mp[str[i]]=1;
    }else{
      mp[str[i]]++;
    }
  }
  char c[mp.size()];
  int count[mp.size()];

  int i=0;
  for(map<char,int>::iterator it=mp.begin();it!=mp.end();it++){
    c[i]=it->first;
    count[i]=it->second;
    i++;
  }

  permuteUtil(mp.size(),str,c,count,0,results);
}

int main(){
  string str="ABCA";
  vector<string> results; //Create the vector results
  permute(str,&results); //Permute finishes all operations and works with the vector results
  for(vector<string>::iterator it=results.begin();it!=results.end();it++){  //Use iterators
    cout<<*it<<endl;  //Print all permutations
  }
  return 0;
}
