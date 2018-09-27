#include <iostream>
#include <stack>
#include <string>

using namespace std;

string s;
int n, p, q;
stack<string> res;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> p >> q >> s;

    int a, b;
    bool done = false;
    for (int i = 0; i * p <= n && !done; i++) {
        for (int j = 0; i * p + j * q <= n; j++) {
            if (i * p + j * q == n) {
                a = i;
                b = j;
                done = true;
                break;
            }
        }
    }
    if (!done) {
        cout << "-1\n";
        return 0;
    }
    cout << a + b << '\n';
    int idx = 0;
    for (int i = 0; i < a; i++, idx += p) {
        cout << s.substr(idx, p) << '\n';
    }
    for (int i = 0; i < b; i++, idx += q) {
        cout << s.substr(idx, q) << '\n';
    }
}