#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    unsigned char c;
    double v;
    string line;
    cin >> t;
    while (t--) {
        unordered_map<unsigned char, double> mp;
        unordered_map<unsigned char, double>::iterator it;
        int k;
        cin >> k;
        cin.ignore();
        double sum = 0;
        while (k--) {
            cin >> c >> v;
            mp[c] = v;
        }
        cin >> k;
        cin.ignore();
        while (k--) {
            getline(cin, line);
            int len = line.length();
            for (int i = 0; i < len; i++) {
                it = mp.find(line[i]);
                if (it != mp.end()) {
                    sum += it->second;
                }
            }
        }
        printf("%.2f$\n", sum / 100);
    }
}