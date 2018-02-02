#include <iostream>
#include <map>

using namespace std;

void permUtil(string& res, unsigned int counts[], char chars[], int n, int idx) {
    if (idx == res.length()) {
        cout << res << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (counts[i]) {
            res[idx] = chars[i];
            counts[i]--;
            permUtil(res, counts, chars, n, idx + 1);
            counts[i]++;
        }
    }
}

void permute(const string& s) {
    map<char, unsigned int> cMap;
    for (char c : s) {
        unsigned int* tmp = &cMap[c];
        (*tmp)++;
    }
    unsigned int counts[cMap.size()];
    char chars[cMap.size()];
    int i = 0;
    for (auto it : cMap) {
        chars[i] = it.first;
        counts[i++] = it.second;
    }
    string res(s);
    permUtil(res, counts, chars, cMap.size(), 0);
}

int main() {
    string word = "aabc";
    permute(word);
}