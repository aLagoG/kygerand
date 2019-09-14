#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

int n, e, k;

bool deleted[MAXN];
bool bad[MAXN];
vector<int> g[MAXN];
int good[MAXN];
int all[MAXN];

struct r_compare {
    bool operator()(const int& l, const int& r) const {
        if (good[l] * all[r] != good[r] * all[l]) {
            return good[l] * all[r] < good[r] * all[l];
        }
        if (all[l] != all[r]) {
            return all[l] < all[r];
        }
        return l < r;
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> e >> k;
    int x;
    for (int i = 0; i < k; i++) {
        cin >> x;
        bad[x] = 1;
    }
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        ++all[a];
        ++all[b];
        if (!bad[a]) {
            ++good[b];
        }
        if (!bad[b]) {
            ++good[a];
        }
        g[a].push_back(b);
        g[b].push_back(a);
    }
    set<int, r_compare> s;
    for (int i = 1; i <= n; i++) {
        if (!bad[i]) {
            s.insert(i);
        }
    }

    r_compare fn;
    int mi, mc = s.size(), c, cu, cd, res = mc;
    mi = *s.begin();
    for (int i = mc; i > 0; --i) {
        for (auto _s : s) {
            cout << _s << ' ';
        }
        cout << endl;
        s.erase(mi);
        deleted[mi] = 1;
        for (auto sib : g[mi]) {
            if (bad[sib] || deleted[sib]) {
                continue;
            }
            s.erase(sib);
            --good[sib];
            s.insert(sib);
        }
        c = *s.begin();
        if (good[c] * all[mi] > good[mi] * all[c]) {
            res = s.size() - 1;
        }
        mi = c;
    }
    cout << res << '\n';
}