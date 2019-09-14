#include <iostream>
#include <string>

using namespace std;

const string h{"hello"};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    cin >> s;
    int r = 0;
    for (int i = 0; i < s.size() && r < h.size(); ++i) {
        if (s[i] == h[r]) {
            ++r;
        }
    }
    cout << (r == h.size() ? "YES" : "NO") << endl;
}
