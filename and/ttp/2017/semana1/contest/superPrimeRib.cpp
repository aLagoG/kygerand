//1052
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

vector<int> primes[9];

int pm[] = {1,3,7,9};

int dmax = 8;

bool isPrime(int n){
	if(n==2||n==3){
		return true;
	}
	if(n<2||n%2==0){
		return false;
	}
	int n2 = sqrt(n)+1;
	for(int i=3;i<=n2;i+=2){
		if(n%i==0){
			return false;
		}
	}
	return true;
}

void criba(int n, int d){
	if(d>dmax){
		return;
	}
	int p = n*10;
	for(int i=0;i<4;i++){
		int pp = p+pm[i];
		if(isPrime(pp)){
			primes[d].push_back(pp);
			criba(pp,d+1);
		}
	}
}

void cribaE(){
	int nums[] = {1,2,3,5,7};
	for(int i=0;i<5;i++){
		if(i>0){
			primes[1].push_back(nums[i]);
		}
		criba(nums[i],2);
	}
}

int main(){
	cribaE();
	int n;
	while(scanf("%d",&n)!=EOF){
		for(auto i : primes[n]){
			int k = i;
			bool done = true;
			for(int j=1;j<n;j++){
				k/=10;
				if(primes[n-j][lower_bound(primes[n-j].begin(),primes[n-j].end(),k)-primes[n-j].begin()]!=k){
					done = false;
					break;
				}
			}
			if(done){
				printf("%d\n",i);
			}
		}
	}
}