#include <string.h>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define MAXN 105

int n, a, b;

int vals[MAXN][2];
map<int, vector<int>> paths;
bool vst[MAXN];
bool value[MAXN];

inline bool canDo(int a, int b, int c, int d) {
    return (a > c && a < d) || (b > c && b < d);
}

bool dfs(int node, int goal) {
    if (vst[node]) {
        return value[node];
    }
    vst[node] = 1;
    if (canDo(vals[node][0], vals[node][1], vals[goal][0], vals[goal][1])) {
        value[node] = 1;
        return true;
    }
    for (auto nn : paths[node]) {
        if (dfs(nn, goal)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int op, idx = 1;
    for (int i = 0; i < n; i++) {
        cin >> op >> a >> b;
        if (op == 1) {
            vals[idx][0] = a;
            vals[idx][1] = b;
            for (int j = 1; j < idx; j++) {
                if (canDo(vals[idx][0], vals[idx][1], vals[j][0], vals[j][1])) {
                    paths[idx].push_back(j);
                }
                if (canDo(vals[j][0], vals[j][1], vals[idx][0], vals[idx][1])) {
                    paths[j].push_back(idx);
                }
            }
            ++idx;
        } else {
            memset(vst, 0, sizeof(vst));
            memset(value, 0, sizeof(value));
            cout << (dfs(a, b) ? "YES" : "NO") << '\n';
        }
    }
}