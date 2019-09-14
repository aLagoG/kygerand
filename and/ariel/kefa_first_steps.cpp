#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, tmp;
    cin >> n;
    int last, max = 1, current = 1;
    cin >> last;
    for (int i = 1; i < n; ++i) {
        cin >> tmp;
        if (tmp >= last) {
            ++current;
        } else {
            if (current > max) {
                max = current;
            }
            current = 1;
        }
        last = tmp;
    }
    cout << (max > current ? max : current) << endl;
}
