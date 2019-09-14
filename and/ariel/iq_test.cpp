#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n, tmp;
    cin >> n;
    int e, o, co = 0, ce = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (tmp & 1) {
            o = i;
            ++co;
        } else {
            e = i;
            ++ce;
        }
    }
    cout << (co == 1 ? o + 1 : e + 1) << endl;
}
