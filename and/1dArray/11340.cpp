#include <string.h>
#include <iostream>

using namespace std;

double vals[256];

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    unsigned char c;
    double v;
    string line;
    cin >> t;
    while (t--) {
        memset(vals, 0, sizeof vals);
        int k;
        cin >> k;
        cin.ignore();
        double sum = 0;
        while (k--) {
            cin >> c >> v;
            vals[c] = v;
        }
        cin >> k;
        cin.ignore();
        while (k--) {
            getline(cin, line);
            int len = line.length();
            for (int i = 0; i < len; i++) {
                if (line[i] >= 0 && line[i] < 256) {
                    sum += vals[line[i]];
                }
            }
        }
        printf("%.2f$\n", sum / 100);
    }
}