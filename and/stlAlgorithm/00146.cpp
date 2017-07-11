#include <algorithm>
#include <iostream>

using namespace std;

string word;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while (cin >> word, word != "#") {
        if (next_permutation(word.begin(), word.end())) {
            cout << word << '\n';
        } else {
            cout << "No Successor\n";
        }
    }
}