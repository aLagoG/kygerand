#include <iostream>

#define MAX 1005

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll ncr[MAX][MAX];
ll colors[MAX];

int main() {
    ncr[0][0] = 1;
    for (int i = 1; i < MAX; i++) {
        ncr[i][0] = 1;
        for (int j = 0; j < MAX; j++) {
            ncr[i][j] = (ncr[i - 1][j] + ncr[i - 1][j - 1]) % MOD;
        }
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> colors[i];
    }
    ll res = 1, count = 0;
    for (int i = 0; i < k; i++) {
        res = (res * ncr[count + colors[i] - 1][colors[i] - 1]) % MOD;
        count += colors[i];
    }

    cout << res << '\n';
}