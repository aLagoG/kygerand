#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> tree[MAXN];
int cat[MAXN];
bool vst[MAXN];

int n, c;

int dfs(int node, int cats) {
    if(vst[node]){
        return 0;
    }
    if (cat[node]) {
        if (++cats > c) {
            return 0;
        }
    } else {
        cats = 0;
    }
    if (node != 1 && tree[node].size() == 1) {
        return 1;
    }
    int res = 0;
    vst[node] = 1;
    for (auto nn : tree[node]) {
        res += dfs(nn, cats);
    }
    return res;
}

int main() {
    cin >> n >> c;
    for (int i = 1; i <= n; ++i) {
        cin >> cat[i];
    }
    int a, b;
    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cout << dfs(1, 0) << '\n';
}