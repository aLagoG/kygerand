#include <iostream>

using namespace std;
typedef unsigned long long ull;

int main() {
    ull a, b;
    cin >> a >> b;
    while (a && b) {
        if (a >= b << 1) {
            a %= b << 1;
        } else if (b >= a << 1) {
            b %= a << 1;
        } else {
            break;
        }
    }
    cout << a << ' ' << b << '\n';
}
