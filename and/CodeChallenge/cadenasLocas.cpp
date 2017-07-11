#include <iostream>

using namespace std;

string a, b, c;

bool dfs(int ia, int ib, int ic) {
    if (ic == c.length()) {
        return true;
    }
    if (a[ia] == c[ic]) {
        if (dfs(ia + 1, ib, ic + 1)) return true;
    }
    if (b[ib] == c[ic]) {
        if (dfs(ia, ib + 1, ic + 1)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while (n--) {
        cin >> a >> b >> c;
        printf("%d\n", dfs(0, 0, 0));
    }
}