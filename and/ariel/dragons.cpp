#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;
pii drg[long(1e3) + 5];

int main() {
    ios_base::sync_with_stdio(0);
    int s, n, d, p;
    cin >> s >> n;
    for (int i = 0; i < n; ++i) {
        cin >> drg[i].first >> drg[i].second;
    }
    sort(drg, drg + n);
    bool can = 1;
    for (int i = 0; i < n; ++i) {
        if (drg[i].first < s) {
            s += drg[i].second;
        } else {
            can = 0;
            break;
        }
    }
    cout << (can ? "YES" : "NO") << endl;
}
