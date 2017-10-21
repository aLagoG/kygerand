#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

void stringPermUtil(int n, char arr[],int arrCount[],string str, vector<string> &results,int level){
  if(level==str.length()){  //If our level is str.length which means that it exceeded its supposed level, we add
    results.push_back(str); //We add to results
    // cout<<str<<endl;
    return;
  }

  for(int i=0;i<n;i++){
    if(arrCount[i]==0){ //If we can not go on, just go to the enxt one which we can use
      continue;
    }
    str[level]=arr[i];  //We assign at the level index of our string the arr[i] char
    arrCount[i]--;  //We reduce the count because we assigned it
    stringPermUtil(n,arr,arrCount,str,results,level+1); //We go down a level to find the next index of the string
    arrCount[i]++;  //Once it comes back, we return the character count
  }
}

void permute(string str,vector<string> &results){
  map<char,int> mp; //Create a map to order keys and assign count to them
  for(int i=0;i<str.length();i++){
    if(mp.find(str[i])==mp.end()){  //Map.find() in c++ returns an iterator to last element if not found
      mp[str[i]]=1;
    }else{  //If found, we just add it to 1
      mp[str[i]]=mp[str[i]]+1;
    }
  }

  char arr[mp.size()];  //Create an array of individual chars
  int arrCount[mp.size()];  //Create an array of amount of char repetitions

  int i=0;
  for (map<char,int>::iterator it=mp.begin(); it!=mp.end(); it++){
    arr[i]= it->first; //first is the key
    arrCount[i]= it->second;  //second is the value
    i++;
  }

  int n=sizeof(arr)/sizeof(arr[0]); //We need the total amount of unique characters
  stringPermUtil(n, arr,arrCount,str,results,0);  //We start the backtrack function which will save everything to results
}

int main(){
  string str="ABCA";
  vector<string> results; //Create the vector results
  permute(str,results); //Permute finishes all operations and works with the vector results
  for(vector<string>::iterator it=results.begin();it!=results.end();it++){  //Use iterators
    cout<<*it<<endl;  //Print all permutations
  }
  return 0;
}
