#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 301

typedef long long ll;
typedef long double ld;

struct point {
    ll x, y;
};

struct line {
    ll a, b, c;
    line() {}
    line(point& p1, point& p2)
        : a(p1.y - p2.y), b(p2.x - p1.x), c(p1.x * p2.y - p2.x * p1.y) {
    }
};

bool intersectionInside(line& l1, line& l2, point& a, point& b) {
    if ((((l1.a + 0.0) / l1.b) == ((l2.a + 0.0) / l2.b))) {
        return false;
    }
    ld resX = ((l1.c * l2.b - l1.b * l2.c) + 0.0) / (l1.b * l2.a - l1.a * l2.b);
    ld resY = ((l1.a * l2.c - l1.c * l2.a) + 0.0) / (l1.b * l2.a - l1.a * l2.b);

    ll minX = min(a.x, b.x);
    ll minY = min(a.y, b.y);
    ll maxX = max(a.x, b.x);
    ll maxY = max(a.y, b.y);

    return ((minX <= resX && resX <= maxX) && (minY <= resY && resY <= maxY));
}

int n;
point h, u;
line lines[MAXN];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> h.x >> h.y >> u.x >> u.y;

    line hu(h, u);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> lines[i].a >> lines[i].b >> lines[i].c;
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (intersectionInside(hu, lines[i], h, u)) {
            count++;
        }
    }

    cout << count << "\n";
}