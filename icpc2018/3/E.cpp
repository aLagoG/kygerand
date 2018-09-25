#include <iostream>
#include <string>

using namespace std;

string line;
string word;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> line >> word;
    int ll, wl, count = 0;
    wl = word.length();
    ll = line.length() - wl;
    bool possible = 1;
    for (int i = 0; i <= ll; i++) {
        possible = 1;
        for (int j = 0; j < wl; j++) {
            if (line[i + j] == word[j]) {
                possible = 0;
                break;
            }
        }
        if (possible) {
            count++;
        }
    }
    cout << count << '\n';
}