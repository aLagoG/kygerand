#include <stdio.h>

bool grid[3][3];
bool next[3][3];

bool is() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grd[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool eq() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] != next[i][j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int cnt = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &grid[i][j]);
            }
        }
        while (!(is() || eq())) {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                }
            }
        }
    }
}