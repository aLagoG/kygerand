//3647
#include <iostream>
#include <map>
#include <set>
#include <queue>

using namespace std;

typedef pair<queue<char>, set<int>> lst;
queue<char> q;
map< queue<char>, set<int> > mp;

int main(){
	string line;
	cin >> line;
	int n = line.length();
	for(auto c : line){
		q.push(c);
	}
	for(int i=1;i<=n;i++){
		if(mp.find(q)!=mp.end()){
			mp[q].insert(i);
		}else{
			int ll[1] = {i};
			mp.insert(lst(q,set<int>(ll,ll+1)));
		}
	}
	for(auto p: mp){
		for(auto in: p.second){
			printf("%d\n",in);
		}
	}
}