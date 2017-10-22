#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

#define MAX 1300000
#define LEN 100021
typedef unsigned long long ll;
ll primes[LEN];

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
    for (ll p = 2; p <= n; p++) {
        if (prime[p]) {
            a[c++] = p;
        }
    }
}

int main() {
    genPrimes(MAX, primes);
    ll a, b;
    while (scanf("%llu %llu", &a, &b), a || b) {
        if (a > b) {
            ll tmp = a;
            a = b;
            b = tmp;
        }
        int idxA = lower_bound(primes, primes + LEN, a) - primes;
        int i = idxA;
        ll max = 0;
        while (i + 1 < LEN && primes[i + 1] <= b) {
            ll var = primes[i + 1] - primes[i];
            if (var > max) {
                max = var;
            }
            i++;
        }
        if (!max) {
            printf("NULL\n");
        } else {
            printf("%llu\n", max);
        }
    }
}