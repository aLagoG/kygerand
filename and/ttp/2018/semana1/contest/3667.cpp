#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string a;
string b;

int main() {
    int n;
    cin >> n;
    cin >> a;
    cout << a;
    while (n--) {
        cin >> b;
        int idx = a.length() - b.length();
        if (idx > a.length()) {
            idx = 0;
        }
        int bix = 0;
        for (; idx < a.length() && bix < b.length(); idx++) {
            if (a[idx] == b[bix]) {
                bix++;
            }else{
                if(a[idx] == b[0]){
                    bix = 1;
                }else{
                    bix = 0;
                }
            }
        }
        for (; bix < b.length(); bix++) {
            cout << b[bix];
        }
        a += b;
        if(a.length() > 2000){
            a = a.substr(a.length()-2000,2000);
        }
    }
    cout << '\n';
}