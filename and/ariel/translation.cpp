#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    bool same = 0;
    if (s.size() == t.size()) {
        same = 1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[t.size() - 1 - i]) {
                same = 0;
                break;
            }
        }
    }
    cout << (same ? "YES" : "NO") << endl;
}
