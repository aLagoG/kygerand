#include <iostream>
#include <set>
#include <string>

#define MAX int(1e4 + 10)

using namespace std;

set<string> s;
string word;
bool dp[MAX][2];

int main() {
    ios::sync_with_stdio(0);
    cin >> word;
    int n = word.length();
    for (int i = n - 2; i >= 5; i--) {
        if (i + 2 == n) {
            dp[i][0] = true;
            s.insert(word.substr(i, 2));
            continue;
        }
        if (i + 3 == n) {
            dp[i][1] = true;
            s.insert(word.substr(i, 3));
            continue;
        }
        if (dp[i + 2][1] ||
            (dp[i + 2][0] && word.substr(i, 2) != word.substr(i + 2, 2))) {
            dp[i][0] = true;
            s.insert(word.substr(i, 2));
        }
        if (dp[i + 3][0] ||
            (dp[i + 3][1] && word.substr(i, 3) != word.substr(i + 3, 3))) {
            dp[i][1] = true;
            s.insert(word.substr(i, 3));
        }
    }
    cout << s.size() << '\n';
    for (auto str : s) {
        cout << str << '\n';
    }
}