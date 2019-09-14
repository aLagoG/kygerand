#include <string.h>
#include <iostream>
#include <vector>

#define N 101

using namespace std;

int n, m;
//[c][n][e]
vector<int> g[N][N];
bool vst[N];

bool dfs(int a, int b, int c) {
    if (a == b) {
        return true;
    }
    if (vst[a] || !g[c][a].size()) {
        return false;
    }
    vst[a] = true;
    for (auto nn : g[c][a]) {
        if (dfs(nn, b, c)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[c][a].push_back(b);
        g[c][b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--) {
        cin >> a >> b;
        int res = 0;
        for (int i = 1; i < N; i++) {
            memset(vst, 0, sizeof(vst));
            res += dfs(a, b, i);
        }
        cout << res << '\n';
    }
}