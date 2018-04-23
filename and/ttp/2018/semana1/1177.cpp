#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n;
    string s;
    while (cin >> n, n) {
        cin >> s;
        int g = s.length() / n;
        for (int i = 0; i < n; i++) {
            reverse(s.begin() + (i * g), s.begin() + ((i + 1) * g));
        }
        cout << s << '\n';
    }
}