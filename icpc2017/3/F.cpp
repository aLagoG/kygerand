#include <stdio.h>
#include <string.h>

typedef unsigned int uint;

int R, C;

char map[30][30];
bool din[30][30];

bool canMove(int r, int c) {
    if (c >= C || r >= R) {
        return 0;
    }
    if (din[r][c]) return 0;
    return map[r][c] == '0';
}

int fill(uint r, uint c) {
    // printf("%d %d\n",r,c);
    din[r][c] = 1;
    int cnt = 1;
    if (canMove(r + 1, c)) {
        cnt += fill(r + 1, c);
    }
    if (canMove(r, c + 1)) {
        cnt += fill(r, c + 1);
    }
    if (canMove(r - 1, c)) {
        cnt += fill(r - 1, c);
    }
    if (canMove(r, c - 1)) {
        cnt += fill(r, c - 1);
    }
    return cnt;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d ", &R, &C);
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                scanf(" %c ", &map[i][j]);
                din[i][j] = 0;
            }
        }
        // for(int i=0;i<R;i++){
        //     for(int j=0;j<C;j++){
        //         printf("%c",map[i][j]);
        //     }
        //     printf("\n");
        // }
        // fill(0,0);
        if (canMove(0, 0)) {
            printf("%d\n", fill(0, 0));
        } else {
            bool run = false;
            for (int i = 0; i < C && !run; i++) {
                if (canMove(i, 0) && !run) {
                    printf("%d\n", fill(i, 0));
                    run = true;
                }
                if (canMove(0, i) && !run) {
                    printf("%d\n", fill(0, i));
                    run = true;
                }
                if (canMove(i, C - 1) && !run) {
                    printf("%d\n", fill(i, C - 1));
                    run = true;
                }
                if (canMove(R - 1, i) && !run) {
                    printf("%d\n", fill(R - 1, i));
                    run = true;
                }
            }
        }
    }
}