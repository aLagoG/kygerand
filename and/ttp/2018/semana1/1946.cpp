#include <stdio.h>

char map[105][105];
bool visited[105][105];
int starts[10005][2];
char dirs[] = {'(', ')'};
int r, c, idx;

bool checkGear(int i, int j, int dir, bool block) {
    if (map[i][j] == '.') {
        return false;
    }
    if (map[i][j] == 'F' && !block) {
        map[i][j] = dirs[dir];
    } else if (block || map[i][j] != dirs[dir]) {
        map[i][j] = 'B';
        block = true;
    }
    if (visited[i][j]) {
        return map[i][j] == 'B';
    }
    visited[i][j] = true;
    ++dir %= 2;
    if (i + 1 < r) {
        if (j - 1 >= 0) {
            // down left
            block |= checkGear(i + 1, j - 1, dir, block);
        }
        // down
        block |= checkGear(i + 1, j, dir, block);
    }
    if (i - 1 >= 0) {
        if (j + 1 < c) {
            // up right
            block |= checkGear(i - 1, j + 1, dir, block);
        }
        // up
        block |= checkGear(i - 1, j, dir, block);
    }
    if (j - 1 >= 0) {
        // left
        block |= checkGear(i, j - 1, dir, block);
    }
    if (j + 1 < c) {
        // right
        block |= checkGear(i, j + 1, dir, block);
    }
    if (block) {
        map[i][j] = 'B';
    }
    return block;
}

int main() {
    while (scanf("%d %d", &r, &c), r || c) {
        idx = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf(" %c", &map[i][j]);
                visited[i][j] = false;
                if (map[i][j] == 'I') {
                    starts[idx][0] = i;
                    starts[idx++][1] = j;
                    map[i][j] = '(';
                } else if (map[i][j] == '*') {
                    map[i][j] = 'F';
                }
            }
        }
        for (int i = 0; i < idx; i++) {
            checkGear(starts[i][0], starts[i][1], 0, false);
        }
        printf("\n");
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
}