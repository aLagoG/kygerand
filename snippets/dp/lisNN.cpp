#include <iostream>
#include <vector>

using namespace std;

//Longest Increasing Subsequence O(n^2)
//RETURNS JUST THE LENGTH

int lis(vector<int> &v){
  if (v.size() == 0) return 0;

  int temp[v.size()];

  //Give all values of temp to 1
  for(int i=0;i<v.size();i++) temp[i]=1;

  //Assign to temp[i] the maximum of any value of temp[j]+1 if v[j] is bigger
  for(int i=1;i<v.size();i++){
    for(int j=0;j<i;j++){
      if(v[j]<=v[i]&&temp[j]+1>temp[i]) temp[i]=temp[j]+1;
    }
  }

  //Find max, max=1 because default values of temp start at 1
  int max=1;
  for(int i=0;i<v.size();i++) if(temp[i]>max)max=temp[i];
  return max;
}

int main() {
    vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    cout << "Length of Longest Increasing Subsequence is " << lis(v)<<endl;
   return 0;
}
