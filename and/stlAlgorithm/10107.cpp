#include <stdio.h>
#include <algorithm>
#include <vector>

#define PH(v,i) v.push_back(i), push_heap(v.begin(), v.end())
#define PMH(v,i) v.push_back(i), push_heap(v.begin(), v.end(), greater<long>())

using namespace std;

vector<long> big;
vector<long> small;
int balance = 0;
long median = 0;

int main(){
	long n;
	while(scanf("%ld",&n)!=EOF){
		switch(balance){
			case 0:
				if(n < median){
					PH(small, n);
					median = small[0];
					balance = -1;
				}else{
					PMH(big, n);
					median = big[0];
					balance = +1;
				}
				break;
			case 1:
				if(n <= median){
					PH(small, n);
				}else{
					PMH(big, n);
					PH(small, big[0]);
					pop_heap(big.begin(), big.end(), greater<long>());
					big.pop_back();
				}
				balance = 0;
				median = (small[0]+big[0])>>1;
				break;
			case -1:
				if(n >= median){
					PMH(big, n);
				}else{
					PH(small,n);
					PMH(big, small[0]);
					pop_heap(small.begin(), small.end());
					small.pop_back();
				}
				balance = 0;
				median = (small[0]+big[0])>>1;
				break;
		}
		printf("%ld\n", median);
	}
}