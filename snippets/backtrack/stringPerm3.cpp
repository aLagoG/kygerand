#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

void permuteUtil(string str, vector<string> *answer, char c[],int count[],int n, int level){
  if(level==str.length()) answer->push_back(str);

  for(int i=0;i<n;i++){
    if(count[i]==0) continue;
    count[i]--;
    str[level]=c[i];
    permuteUtil(str,answer,c,count,n,level+1);
    count[i]++;
  }
}

void permute(string str, vector<string> *answer){
  map<char,unsigned int> mp;

  for(int i=0;i<str.length();i++){
    if(mp.find(str[i])==mp.end()) mp[str[i]]=1;
    else mp[str[i]]++;
  }

  char c[mp.size()];
  int count[mp.size()];

  int i=0;
  for(map<char,unsigned int>::iterator it=mp.begin();it!=mp.end();it++){
    c[i]=it->first;
    count[i]=it->second;
    i++;
  }

  permuteUtil(str, answer, c, count, mp.size(), 0);

}

int main(){
  string str="chan";
  vector<string> answer;
  permute(str,&answer);
  for(vector<string>::iterator it=answer.begin();it!=answer.end();it++) printf("%s\n",it->c_str());
}
