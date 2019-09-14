#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, min, max, cnt = 0, tmp;
    cin >> n >> min;
    max = min;
    for (int i = 1; i < n; ++i) {
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
            ++cnt;
        }
        if (tmp < min) {
            min = tmp;
            ++cnt;
        }
    }
    cout << cnt << endl;
}
