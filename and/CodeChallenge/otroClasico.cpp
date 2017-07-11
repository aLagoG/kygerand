#include <stdio.h>
#include <string.h>
#include <array>

using namespace std;

#define N 15485864
#define M 1000001

typedef unsigned long long ll;

ll primes[N];
ll max = M;
ll n;
array<bool, N> arr;

void cribaE() {
    ll p = 2;
    ll c = 0;
    while (p < N && c < n) {
        primes[c++] = p;
        // printf("%llu\n",primes[c-1]);
        for (ll i = p; i < N; i += p) {
            arr[i] = true;
        }
        while (p < N && arr[++p])
            ;
    }
}

int main() {
    scanf("%llu", &n);
    cribaE();
    printf("%llu\n", primes[n - 1]);
}