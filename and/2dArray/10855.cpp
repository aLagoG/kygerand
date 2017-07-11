#include <stdio.h>

#define S 500

char big[S][S], small[S][S];

int main() {
    int N, n;
    while (scanf("%d %d", &N, &n), N || n) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf(" %c", &big[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %c", &small[i][j]);
            }
        }
        int buff = N - n + 1;
        int cnt = 0;
        for (int i = 0; i < buff; i++) {
            for (int j = 0; j < buff; j++) {
                bool br = 1;
                for (int k = 0; k < n && br; k++) {
                    for (int z = 0; z < n; z++) {
                        if (small[k][z] != big[i + k][j + z]) {
                            br = 0;
                            break;
                        }
                    }
                }
                if (br) {
                    cnt++;
                }
            }
        }
        printf("%d ", cnt);

        cnt = 0;
        for (int i = 0; i < buff; i++) {
            for (int j = 0; j < buff; j++) {
                bool br = 1;
                for (int k = 0; k < n && br; k++) {
                    for (int z = 0; z < n; z++) {
                        // printf("%d,%d %d,%d %c %c\n", n-1-z,k,
                        // i+k,j+z,small[n-1-z][k],big[i+k][j+z]);
                        if (small[n - 1 - z][k] != big[i + k][j + z]) {
                            br = 0;
                            break;
                        }
                    }
                }
                if (br) {
                    cnt++;
                }
            }
        }
        printf("%d ", cnt);

        cnt = 0;
        for (int i = 0; i < buff; i++) {
            for (int j = 0; j < buff; j++) {
                bool br = 1;
                for (int k = 0; k < n && br; k++) {
                    for (int z = 0; z < n; z++) {
                        if (small[n - k - 1][n - z - 1] != big[i + k][j + z]) {
                            br = 0;
                            break;
                        }
                    }
                }
                if (br) {
                    cnt++;
                }
            }
        }
        printf("%d ", cnt);

        cnt = 0;
        for (int i = 0; i < buff; i++) {
            for (int j = 0; j < buff; j++) {
                bool br = 1;
                for (int k = 0; k < n && br; k++) {
                    for (int z = 0; z < n; z++) {
                        if (small[z][n - k - 1] != big[i + k][j + z]) {
                            br = 0;
                            break;
                        }
                    }
                }
                if (br) {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
}