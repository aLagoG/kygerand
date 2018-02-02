#include <iostream>

using namespace std;

void swap(char& a, char& b) {
    if (a != b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
}

void permute(string& s, int st) {
    if (st == s.length()) {
        cout << s << endl;
        return;
    }
    permute(s, st + 1);
    for (int i = st + 1; i < s.length(); i++) {
        swap(s[st], s[i]);
        permute(s, st + 1);
        swap(s[st], s[i]);
    }
}

int main() {
    string word = "abc";
    permute(word, 0);
}