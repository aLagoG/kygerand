#include <iostream>
using namespace std;
/*
	Eratosthenes' sieve that stores in an array from 0 to n the
	smallest prime factor of the number in its index

	Parameters:
		-n: the number to which you want to generate SPF
		-spf: an array of n+1 elements to store the factors
 */
#include <string.h>
typedef unsigned long long ll;

void getSPF(ll n, ll spf[]) {

	spf[0] = 0; //for consistency and easier debug
	for (ll i = 1; i <= n; i++) {
		spf[i] = (i & 1) ? i : 2;
	}

	for (ll p = 3; p * p <= n; p++) {
		if (spf[p] == p) {
			for (ll i = p * p; i <= n; i += p) {
				if (spf[i] == i) {
					spf[i] = p;
				}
			}
		}
	}
}

int main() {
	ll a[14];
	getSPF(13, a);
	for (auto p : a) {
		cout << p << '\n';
	}
}