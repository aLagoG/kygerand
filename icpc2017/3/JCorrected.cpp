#include<iostream>
#include<vector>
#include<stack>
using namespace std;
string a, b;
vector<bool> v;
stack<char> s;
int i;
void dfs( int x, int y ){
	if( x==a.size() && y==b.size() ){
    printf("%c",v[0]?'i':'o');
		for( i=1; i<v.size(); ++i ){
      printf(" %c",v[i]?'i':'o');
		}
		printf("\n");
		return;
	}
	// push
	if( x<a.size() ){
		v.push_back(1);
		s.push(a[x]);
		dfs(x+1,y);
		v.pop_back();
		s.pop();
	}
	// pop if possible
	if( !s.empty() && y<b.size() && s.top()==b[y] ){
		v.push_back(0);
		char c = s.top();
		s.pop();
		dfs(x,y+1);
		s.push(c);
		v.pop_back();
	}
}
int main(){
  int t;
  scanf("%d",&t);
	while(t--){
    cin>>a>>b;
		v.clear();
    cout<<"Output for "<<a<<" "<<b<<endl<<"[\n";
		dfs(0,0);
    printf("]\n");
	}
}
