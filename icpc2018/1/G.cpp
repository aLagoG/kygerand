#include <stdio.h>

bool map[105][105];
bool vst[105][105];
int cnt = 0;
unsigned long long profit = 0;
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int search(int i, int j) {
    vst[i][j] = 1;
    int num = 1;
    int ni, nj;
    for (int k = 0; k < 4; k++) {
        ni = i + dir[k][0];
        nj = j + dir[k][1];
        if (map[ni][nj] && !vst[ni][nj]) {
            num += search(ni, nj);
        }
    }
    return num;
}

int main() {
    int t, g, r, c;
    scanf("%d %d %d %d", &t, &g, &r, &c);
    int tmp;
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            scanf("%d", &tmp);
            map[i][j] = tmp == 1;
        }
    }
    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (map[i][j] && !vst[i][j]) {
                int lC = search(i, j);
                if (lC >= t) {
                    cnt++;
                    profit += (lC - t) * g;
                }
            }
        }
    }
    printf("%d %llu\n", cnt, profit);
}