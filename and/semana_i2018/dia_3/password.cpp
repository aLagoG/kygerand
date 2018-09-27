#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

const int MAXN = 1e6+5;

int suffix[MAXN];
int infix[MAXN];
string s;

void z(int lim, int *arr) {
    int l = 1, r = 1;
    for (int i = 1; i < lim; i++) {
        int t = min(arr[i - l], max(0, r - i));
        while (t + i < lim && s[t + i] == s[t]) t++;
        arr[i] = t;
        if (i + t > r) {
            l = i;
            r = i + t;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> s;
    int n = s.length();
    z(n, suffix);
    z(n - 1, infix);
    int max = 0;
    for (int i = 0; i < n; i++) {
        if (infix[i] > max) {
            max = infix[i];
        }
    }
    int maxs = 0, maxi = -1;
    for (int i = 0; i < n; i++) {
        if (suffix[i] + i == n && suffix[i] > maxs && suffix[i] <= max) {
            maxi = i;
            maxs = suffix[i];
        }
    }
    if (maxi == -1) {
        cout << "Just a legend\n";
    } else {
        cout << s.substr(maxi, maxs) << '\n';
    }
}