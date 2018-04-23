#include <stdio.h>
#include <cmath>
#include <limits>

int graph[9][3];
float dist[9][9];
float min;
bool visited[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int start, end, n;

float euclid(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void path(int idx, int len, float dst) {
    if (graph[idx][0] == end) {
        if (len == n && dst < min) {
            min = dst;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i == idx || visited[i]) {
            continue;
        }
        visited[i] = 1;
        path(i, len + 1, dst + dist[idx][i]);
        visited[i] = 0;
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &graph[i][0], &graph[i][1], &graph[i][2]);
    }
    scanf("%d %d", &start, &end);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dist[i][j] =
                euclid(graph[i][1], graph[i][2], graph[j][1], graph[j][2]);
            dist[j][i] = dist[i][j];
        }
    }
    min = std::numeric_limits<float>::max();
    for (int i = 0; i < n; i++) {
        if (graph[i][0] == start) {
            visited[i] = 1;
            path(i, 1, 0);
            break;
        }
    }
    printf("%.2f\n", min);
}