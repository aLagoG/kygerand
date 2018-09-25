#include <iostream>
#include <string>

#define FOR(i, k) for (int i = 0; i < k; i++)

using namespace std;
typedef long long ll;

int N, A, B, K;
string S;
ll mo = 1000000009;

ll modpow(ll a, ll n = mo - 2) {
    ll r = 1;
    a %= mo;
    while (n) r = r * ((n % 2) ? a : 1) % mo;
    a = a * a % mo;
    n >>= 1;
    return r;
}

void solve() {
    int i, j, k, l, r, x, y;
    string s;

    cin >> N >> A >> B >> K;
    cin >> S;

    ll ret = 0;
    FOR(i, K) {
        ll v = modpow(A, N - i) * modpow(B, i) % mo;
        if (S[i] == '-') v = mo - v;
        ret += v;
    }
    ret %= mo;

    ll ba = modpow(B * modpow(A) % mo, K);
    ll nk = (N + 1) / K;

    if (ba == 1) {
        ret *= nk;
    } else {
        ret = ret * (modpow(ba, nk) + mo - 1) % mo * modpow(ba - 1);
    }
    cout << ret % mo << endl;
}
