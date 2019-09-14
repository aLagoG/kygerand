#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

#define max(a, b) ((a > b) ? a : b)

const int MAXN = 1e5 + 5;

int a[MAXN];
int b[MAXN];
int v[MAXN << 1];
int n2, n;

struct suffix {
    int index, rank1, rank2, str;
    bool operator<(const suffix &b) {
        return rank1 == b.rank1 ? rank2 < b.rank2 : rank1 < b.rank1;
    }
};

int LCString() {
    vector<suffix> suffixes(n2);
    for (int i = 0; i < n2; i++) {
        suffixes[i].index = i;
        suffixes[i].rank1 = v[i];
        suffixes[i].rank2 = (i + 1 < n2) ? v[i + 1] : -1;
        suffixes[i].str = i < n;
    }

    sort(suffixes.begin(), suffixes.end());

    vector<int> idx(n2);

    for (int k = 4; k < (n2 << 1); k <<= 1) {
        int rank = 0;
        int prev_rank = suffixes[0].rank1;
        suffixes[0].rank1 = rank;
        idx[suffixes[0].index] = 0;

        for (int i = 1; i < n2; i++) {
            if (suffixes[i].rank1 == prev_rank &&
                suffixes[i].rank2 == suffixes[i - 1].rank2) {
                prev_rank = suffixes[i].rank1;
                suffixes[i].rank1 = rank;
            } else {
                prev_rank = suffixes[i].rank1;
                suffixes[i].rank1 = ++rank;
            }
            idx[suffixes[i].index] = i;
        }

        for (int i = 0; i < n2; i++) {
            int nIdx = suffixes[i].index + (k >> 1);
            suffixes[i].rank2 = (nIdx < n2) ? suffixes[idx[nIdx]].rank1 : -1;
        }

        sort(suffixes.begin(), suffixes.end());
    }

    int res = 0;
    for (int i = 2; i < n2; i++) {
        if (suffixes[i].str != suffixes[i - 1].str) {
            int len = 0;
            while (suffixes[i].index + len < n2 &&
                   suffixes[i - 1].index + len < n2) {
                if (v[suffixes[i].index + len] !=
                    v[suffixes[i - 1].index + len]) {
                    break;
                }
                ++len;
            }
            if (len > res) {
                res = len;
            }
        }
    }

    return res;
}

int main() {
    scanf("%d", &n);
    n2 = n * 2 + 1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        v[i] = a[i];
    }
    v[n] = -1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        v[n + i] = b[i];
    }
    printf("%d\n", LCString());
}