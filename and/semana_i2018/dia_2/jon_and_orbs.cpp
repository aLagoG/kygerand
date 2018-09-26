#include <iostream>

#define MAX int(1e3 + 2)
#define E 1e-7
#define MAX_DAYS int(1e4 * 1.5)

using namespace std;

double dp[MAX_DAYS + 1][MAX];

int main() {
    ios::sync_with_stdio(0);
    int k, q;
    cin >> k >> q;
    dp[0][0] = 1;
    for (int days = 1; days <= MAX_DAYS; days++) {
        for (int orbs = 1; orbs <= k; orbs++) {
            dp[days][orbs] = (orbs * dp[days - 1][orbs] +
                              (k - orbs + 1) * dp[days - 1][orbs - 1]) /
                             k;
        }
        if (dp[days][k] * 2000 >= 1000) {
            break;
        }
    }
    int query;
    while (q--) {
        cin >> query;
        for (int i = 1; i <= MAX_DAYS; i++) {
            if (dp[i][k] * 2000 >= query - E) {
                cout << i << '\n';
                break;
            }
        }
    }
}