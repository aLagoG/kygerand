#include <stdio.h>
#include <string.h>

struct event {
    int start, end, score;
};

int v;
event venues[10][1000];
int sizes[10];
bool valid[10];
int idx[10];

int search(int current) {
    bool leaf = true;
    for (int i = 0; i < v; i++) {
        if (idx[i] + 1 < sizes[i]) {
            leaf = false;
            break;
        }
    }
    if (leaf) {
        for (int i = 0; i < v; i++) {
            if (!valid[i]) {
                return -1;
            }
        }
        return venues[current][idx[current]].score;
    }
    event self = venues[current][idx[current]];
    int next = -1;
    int next_idx = -1;
    for (int i = 0; i < v; i++) {
        int st = idx[i];
        while (idx[i] + 1 <= sizes[i] && venues[i][idx[i]].start < self.end) {
            idx[i]++;
        }
        if (idx[i] + 1 <= sizes[i]) {
            bool last = valid[i];
            valid[i] = 1;
            int val = search(i);
            valid[i] = last;
            if (val > next) {
                next = val;
                next_idx = i;
            }
        }
        idx[i] = st;
    }
    if (next != -1) {
        valid[next_idx] = 1;
        return next + self.score;
    }
    return next;
}

int main() {
    memset(valid, 0, sizeof(bool) * 10);
    memset(idx, 0, sizeof(int) * 10);
    scanf("%d", &v);
    for (int i = 0; i < v; i++) {
        scanf("%d", &sizes[i]);
        for (int j = 0; j < sizes[i]; j++) {
            scanf("%d %d %d", &venues[i][j].start, &venues[i][j].end,
                  &venues[i][j].score);
        }
    }
    int answer = -1;
    for (int i = 0; i < v; i++) {
        valid[i] = 1;
        int val = search(i);
        valid[i] = 0;
        if (val > answer) {
            answer = val;
        }
    }
    printf("%d\n", answer);
}