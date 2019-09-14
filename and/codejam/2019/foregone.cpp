#include <iostream>

using namespace std;

typedef unsigned int uint;

const int abv[]{1, 2, 3, 5, 6, 7, 8, 9, 0};
uint obj;

int src(int crt) {
    if (crt > obj) {
        return -1;
    }
    int rm = obj - crt;
    bool ps = 1;
    while (rm) {
        int d = rm % 10;
        rm /= 10;
        if (d == 4) {
            ps = 0;
            break;
        }
    }
    if (ps) {
        return crt;
    }
    for (auto d : abv) {
        int tmp = src(crt * 10 + d);
        if (tmp != -1) {
            return tmp;
        }
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> obj;
        for (auto d : abv) {
            int tmp = src(d);
            if (tmp != -1) {
                cout << "Case #" << i + 1 << ": " << tmp << ' ' << obj - tmp
                     << endl;
                break;
            }
        }
    }
}
