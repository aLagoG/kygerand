#include <iostream>

using namespace std;

int n;
const int valid[2]{4, 7};

bool search(int current) {
    if (n % current == 0) {
        return true;
    }
    if (current > n) {
        return false;
    }
    for (auto v : valid) {
        if (search(current * 10 + v)) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    cout << (search(4) || search(7) ? "YES" : "NO") << endl;
}
