#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <numeric>

using namespace std;

typedef long long ll;

#define MAX int(1e5 + 10)

ll a[MAX];
ll sum[MAX];
ll dp[MAX][2];

// version with no offset initializing the first values
int main() {
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    cin >> a[0];
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        sum[i] = abs(a[i - 1] - a[i]);
    }
    ll res = -ll(1e11);
    dp[0][0] = sum[0];
    dp[0][1] = -sum[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(sum[i], dp[i - 1][1] + sum[i]);
        dp[i][1] = max(-sum[i], dp[i - 1][0] - sum[i]);
        res = max(max(dp[i][0], dp[i][1]), res);
    }
    cout << res << '\n';
}

// version with an offset
// int main() {
//     ios::sync_with_stdio(0);
//     int n;
//     cin >> n;
//     cin >> a[1];
//     for (int i = 2; i <= n; i++) {
//         cin >> a[i];
//         sum[i] = abs(a[i] - a[i - 1]);
//     }
//     ll res = -ll(1e11);
//     for (int i = 2; i <= n; i++) {
//         dp[i][0] = max(sum[i], dp[i - 1][1] + sum[i]);
//         dp[i][1] = max(-sum[i], dp[i - 1][0] - sum[i]);
//         res = max(max(dp[i][0], dp[i][1]), res);
//     }
//     cout << res << '\n';
// }