#include <stdio.h>
#include <unordered_set>

using namespace std;

unordered_set<int> s;

int main(){
	int t;
	while(scanf("%d",&t)!=EOF){
		if(s.find(t)==s.end()){
			s.insert(t);
		} else {
			s.erase(t);
		}
	}
	for(auto i : s){
		printf("%d\n",i);
	}
}