#include <iostream>
/*
	Eratosthenes' sieve that collects primes on a vector 
	use when you need a O(n) list of ordered primes but 
	you don't know how many primes will result from the sieve

	Pros:
		- Don't need to know number of primes 
	Cons:
		- Multiple relocations will probably make it slower

	Parameters:
		-n: the number to which you want to generate primes
		-v: a vector where you want to collect them
 */
#include <string.h>
#include <vector>
typedef unsigned long long ll;
using namespace std;

void genPrimes(ll n, vector<ll>& v) {
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (ll p = 2; p * p <= n; p++) {
		if (prime[p]) {
			for (ll i = p * p; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}
	for(ll p = 2;p<=n;p++){
		if(prime[p]){
			v.push_back(p);
		}
	}
}

int main(){
	vector<ll> v;
	genPrimes(13, v);
	for(auto p:v){
		cout << p << '\n';
	}
}