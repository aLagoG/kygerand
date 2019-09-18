#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int N;
    int temp;
    int prev;
    vector<int> v;
    vector<int> diff;
    scanf("%d", &N);
    for (int iii = 0; iii < N; iii++) {
        scanf("%d", &temp);
        v.push_back(temp);
        if (iii != 0) {
            diff.push_back(temp - prev);
        }
        prev = temp;
    }

    long long tot = 0;
    for (int i = v.size() - 1; i >= 0; i--)
        tot += i * v[i] - (v.size() - 1 - i) * v[i];

    int countMinus1 = 0;
    int countPlus1 = 0;

    unordered_map<int, int> mp;
    for (int i = 0; i < v.size(); i++) {
        mp[v[i]]++;
    }

    for (int i = 0; i < v.size(); i++) {
        int x = v[i];
        tot -= mp[x + 1];
        tot += mp[x - 1];
        mp[x]--;
    }

    printf("%lld\n", tot);
    // printf("%lld\n", tot - countMinus1 + countPlus1);

    return 0;
}
