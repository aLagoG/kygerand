//2709
#include <stdio.h>
#include <set>

using namespace std;

int main(){
	int n,p;
	set<int> s;
	scanf("%d %d",&n,&p);
	int res = n;
	while(n--){
		int k;
		scanf("%d",&k);
		if(s.find(k)==s.end()){
			res--;
			s.insert(k);
		}
	}
	printf("%d\n",res);
}