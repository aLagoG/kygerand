#include <cmath>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

vector<int> primes;

void genPrimes(int n, vector<int>& v) {
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            v.push_back(p);
        }
    }
}

int factorize(int n) {
    int sq = sqrt(n) + 1;
    int res = 0;
    for (int i = 0; primes[i] <= sq && n != 1; i++) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            res = primes[i];
        }
    }
    if (n != 1) {
        res = n;
    }
    return res;
}

int main() {
    int x2, fac;
    cin >> x2;
    genPrimes(x2 >> 1, primes);
    fac = factorize(x2);
    int x1_min = x2 - fac + 1;
    int x0 = x2;
    for(int i = x1_min;i<=x2;i++){
        fac = factorize(i);
        if(fac == i){
            continue;
        }
        int tmp = i - fac + 1;
        if(tmp < x0){
            x0 = tmp;
        }
    }
    cout << x0 << '\n';
}
