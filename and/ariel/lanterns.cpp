#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // ios_base::sync_with_stdio(0);
    vector<int> v;
    int n, l, tmp;
    cin >> n >> l;
    for (int i = 0; i < n; ++i) {
        scanf(" %d", &tmp);
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    double res = max(v[0], l - v[n - 1]);
    for (int i = 0; i + 1 < n; ++i) {
        double crt = (v[i + 1] - v[i]) / 2.0;
        res = max(res, crt);
    }
    printf("%.10f\n", res);
}
