#include <iostream>

typedef unsigned long long ull;

using namespace std;

int counts[10];

ull fact[]{1,       1,        2,         6,           24,
           120,     720,      5040,      40320,       362880,
           3628800, 39916800, 479001600, 6227020800l, 87178291200l};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    string s;
    while (t--) {
        for (int i = 0; i < 10; i++) {
            counts[i] = 0;
        }
        cin >> s;
        ull size = s.length();
        for (int i = 0; i < size; i++) {
            counts[s[i] - '0']++;
        }
        ull perms = fact[size];
        for (int i = 0; i < 10; i++) {
            perms /= fact[counts[i]];
        }
        ull sum = 0;
        if (perms == 1) {
            ull mul = 1;
            for (int i = size - 1; i >= 0; i--) {
                sum += (s[i] - '0') * mul;
                mul *= 10;
            }
        } else {
            ull ds = 0;
            for (int i = 0; i < 10; i++) {
                ds += i * counts[i] * perms / size;
            }
            sum = ds;
            for (int i = 0; i < size - 1; i++) {
                ds *= 10;
                sum += ds;
            }
        }
        cout << perms << ' ' << sum << '\n';
    }
}