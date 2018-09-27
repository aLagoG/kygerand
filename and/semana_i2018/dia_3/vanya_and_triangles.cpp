#include <iostream>

using namespace std;

const int MAXN = 2003;

typedef pair<int, int> point;
int n;
point p[MAXN];

int cross(const point &a, const point &b, const point &c) {
    return (b.first - a.first) * (c.second - a.second) -
           (b.second - a.second) * (c.first - a.first);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    long long count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (cross(p[i], p[j], p[k])) {
                    count++;
                }
            }
        }
    }
    cout << count << '\n';
}