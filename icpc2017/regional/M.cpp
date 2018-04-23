#include <stdio.h>
#include <algorithm>
#include <set>
#include <vector>

#define MAX 100005
#define TOTAL 500005

#define MOD 1000000007

using namespace std;

typedef unsigned long long ull;

int pow(ull x, unsigned int y, ull m) {
    ull res = 1;
    x %= m;
    while (y) {
        if (y & 1) {
            res = (res * x) % m;
        }
        y >>= 1;
        x = (x * x) % m;
    }
    return res;
}

int starts[MAX];
int all[TOTAL];
int sa[TOTAL];
int idx = 0;

struct suffix {
    int index, rank1, rank2;
    bool operator<(const suffix &b) {
        return rank1 == b.rank1 ? rank2 < b.rank2 : rank1 < b.rank1;
    }
};

bool inv(const suffix &a, const suffix &b) {
    return a.index < b.index;
}

void buildSuffixArray(int n) {
    vector<suffix> suffixes(n);
    for (int i = 0; i < n; i++) {
        suffixes[i].index = i;
        suffixes[i].rank1 = all[i];
        suffixes[i].rank2 = (i + 1 < n) ? all[i + 1] : -1;
    }

    sort(suffixes.begin(), suffixes.end());

    vector<int> idx(n);

    for (int k = 4; k < (n << 1); k <<= 1) {
        int rank = 0;
        int prev_rank = suffixes[0].rank1;
        suffixes[0].rank1 = rank;
        idx[suffixes[0].index] = 0;

        for (int i = 1; i < n; i++) {
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

        for (int i = 0; i < n; i++) {
            int nIdx = suffixes[i].index + (k >> 1);
            suffixes[i].rank2 = (nIdx < n) ? suffixes[idx[nIdx]].rank1 : -1;
        }

        sort(suffixes.begin(), suffixes.end());
    }

    for (int i = 0; i < n; i++) {
        suffixes[i].rank1 = i;
    }

    sort(suffixes.begin(), suffixes.end(), inv);

    for (int i = 0; i < n; i++) {
        sa[i] = suffixes[i].rank1;
    }
}

struct comp {
    bool operator()(const int &a, const int &b) {
        return all[a] == all[b] ? sa[a] < sa[b] : all[a] < all[b];
    }
};

set<int, comp> s;

int main() {
    int n, D = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        D += k;
        starts[i] = idx;
        for (int j = 0; j < k; j++) {
            int val;
            scanf("%d", &val);
            all[idx++] = val;
        }
        all[idx++] = 305;
    }

    // this is the inverse of a suffix array i.e at index[i] of sa there is the
    // rank of the suffix starting at i
    buildSuffixArray(idx);

    for (int i = 0; i < n; i++) {
        s.insert(starts[i]);
    }

    ull mul;
    ull res = 0;
    while (D) {
        int current = *s.begin();
        mul = pow(365, D--, MOD);
        res += (all[current] * mul) % MOD;
        s.erase(s.begin());
        if (all[current + 1] != 305) {
            s.insert(current + 1);
        }
    }
    printf("%lld\n", res % MOD);
}