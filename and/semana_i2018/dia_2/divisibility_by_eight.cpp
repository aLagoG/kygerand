#include <iostream>

using namespace std;

string s;

int main() {
    ios::sync_with_stdio(0);
    cin >> s;
    int res, len = s.length(), pi, pj, pk;
    bool worked = false;
    for (int i = 0; i < len && !worked; i++) {
        pi = s[i] - '0';
        res = pi;
        if (res % 8 == 0) {
            worked = true;
            break;
        }
        for (int j = i + 1; j < len && !worked; j++) {
            pj = s[j] - '0';
            res = pi * 10 + pj;
            if (res % 8 == 0) {
                worked = true;
                break;
            }
            for (int k = j + 1; k < len && !worked; k++) {
                pk = s[k] - '0';
                res = pi * 100 + pj * 10 + pk;
                if (res % 8 == 0) {
                    worked = true;
                    break;
                }
            }
        }
    }
    if (worked) {
        cout << "YES" << '\n' << res << '\n';
    } else {
        cout << "NO" << '\n';
    }
}
