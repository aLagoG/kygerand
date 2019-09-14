#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, m, tmp;
    vector<int> v;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> tmp;
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end());
    int l = v[0], r = v[n - 1];
    for (int i = 1; i + n - 1 < m; ++i) {
        if (r - l > v[i + n - 1] - v[i]) {
            l = v[i];
            r = v[i + n - 1];
        }
    }
    cout << r - l << endl;
}
