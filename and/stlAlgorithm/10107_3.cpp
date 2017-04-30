#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

vector<long> v;

int main(){
	long n;
	while(scanf("%ld",&n)!=EOF){
		v.push_back(n);
		if(v.size()&1){
			nth_element(v.begin(), v.begin() + (v.size()>>1), v.end());
			printf("%ld\n", v[v.size()>>1]);
		}else{
			long r;
			nth_element(v.begin(), v.begin() + (v.size()>>1)-1, v.end());
			r = v[(v.size()>>1)-1];
			nth_element(v.begin(), v.begin() + (v.size()>>1), v.end());
			printf("%ld\n", (r+v[(v.size()>>1)])>>1);
		}
	}
}