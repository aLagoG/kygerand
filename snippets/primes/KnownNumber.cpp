#include <iostream>
using namespace std;
/*
	Eratosthenes' sieve that collects primes on an array 
	use when you need a O(n) list of ordered primes and 
	you know how many there will be

	Pros:
		- Faster because it doesn't rellocate 
	Cons:
		- You have to know the number of primes in range

	Parameters:
		-n: the number to which you want to generate primes
		-a: an array of the correct size to store the resulting primes
 */
#include <string.h>
typedef unsigned long long ll;

void genPrimes(ll n, ll a[]) {
	bool prime[n + 1];
	memset(prime, true, sizeof(prime));

	for (ll p = 2; p * p <= n; p++) {
		if (prime[p]) {
			for (ll i = p * p; i <= n; i += p) {
				prime[i] = false;
			}
		}
	}
	ll c = 0;
	for(ll p = 2;p<=n;p++){
		if(prime[p]){
			a[c++] = p;
		}
	}
}

int main(){
	ll a[6];
	genPrimes(13, a);
	for(auto p:a){
		cout << p << '\n';
	}
}