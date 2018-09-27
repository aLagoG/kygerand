#include <stdio.h>
#include <set>
#include <utility>
#include <vector>

using namespace std;

const int MAXN = 1e+2;

int n, x0, y0;

typedef pair<int, int> point;

set<point> s;

int cross(int x0, int y0, const point &a, const point &b) {
    return (a.first - x0) * (b.second - y0) - (a.second - y0) * (b.first - x0);
}

int main() {
    scanf("%d %d %d", &n, &x0, &y0);
    int x, y;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        s.emplace(x, y);
    }
    int n = s.size();
    vector<point> v(s.begin(), s.end());
    vector<bool> dead(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (dead[i]) {
            continue;
        }
        dead[i] = true;
        count++;
        for (int j = i + 1; j < n; j++) {
            if (dead[j]) {
                continue;
            }
            if (!cross(x0, y0, v[i], v[j])) {
                dead[j] = true;
            }
        }
    }
    printf("%d\n", count);
}