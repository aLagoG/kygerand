#include <stdio.h>

typedef unsigned long long ull;

const int MAXN = 1e5 + 5;
int board[MAXN][4];
ull dp[MAXN][11];
char moves[] = {1, 2, 4, 8, 5, 9, 10};
#define MM 7

ull sum(int i, char m) {
    ull r = 0;
    for (char j = 0; j < 4; ++j) {
        if ((1 << j) & m) {
            r += board[i][j];
        }
    }
    return r;
}

ull maxp(int i, char m) {
    ull r = 0;
    for (char j = 0; j < MM; ++j) {
        if (moves[j] & m) {
            continue;
        }
        ull t = sum(i, m);
        if (t > r) {
            r = t;
        }
    }
    return r;
}

ull f(int i, char m) {
    if (!i) {
        return maxp(i, m);
    }
    ull r = 0;
    for (char j = 0; j < MM; ++j) {
        if (moves[j] & m) {
            continue;
        }
        ull t = sum(i, moves[j]) + f(i - 1, moves[j]);
        if (t > r) {
            r = t;
        }
    }
    return r;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &board[j][i]);
        }
    }
    printf("%d\n", f(n - 1, 0));
}