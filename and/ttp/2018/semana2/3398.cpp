#include <stdio.h>

bool map[10][10];
int offs;
bool doable = false;

enum direction { up = 0, right = 1, down = 2, left = 3 };

void ff(int i, int j, direction d) {
    if (doable || map[i][j]) {
        return;
    }
    offs--;
    map[i][j] = 1;
    if (!offs) {
        doable = true;
    }
    switch (d) {
        case up:
            if (map[i - 1][j]) {
                ff(i, j - 1, left);
                ff(i, j + 1, right);
            } else {
                ff(i - 1, j, d);
            }
        case right:
            if (map[i][j + 1]) {
                ff(i - 1, j, up);
                ff(i + 1, j, down);
            } else {
                ff(i, j + 1, d);
            }
        case down:
            if (map[i + 1][j]) {
                ff(i, j - 1, left);
                ff(i, j + 1, right);
            } else {
                ff(i + 1, j, d);
            }
        case left:
            if (map[i][j - 1]) {
                ff(i - 1, j, up);
                ff(i + 1, j, down);
            } else {
                ff(i, j - 1, d);
            }
    }
    map[i][j] = 0;
    offs++;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i - 1 <= n; i++) map[i][0] = 1;
    for (int i = 0; i - 1 <= n; i++) map[0][i] = 1;
    for (int i = 0; i - 1 <= n; i++) map[i][n + 1] = 1;
    for (int i = 0; i - 1 <= n; i++) map[n + 1][i] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char tmp;
            scanf(" %c", &tmp);
            map[i][j] = tmp == 'o';
            offs += tmp == 'x';
        }
    }
    // printf("offs: %d\n", offs);
    // for (int i = 0; i - 1 <= n; i++) {
    //     for (int j = 0; j - 1 <= n; j++) {
    //         printf("%d", map[i][j]);
    //     }
    //     printf("\n");
    // }
    for (int i = 1; i <= n && !doable; i++) {
        for (int j = 1; j <= n && !doable; j++) {
            if (!map[i][j]) {
                for (int k = 0; k < 4 && !doable; k++) {
                    ff(i, j, (direction)k);
                }
            }
        }
    }
    printf("%s\n", doable ? "Yes" : "No");
}