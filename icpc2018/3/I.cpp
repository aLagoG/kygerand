#include <stdio.h>
#include <bitset>
#include <unordered_map>

using namespace std;

#define N 1000

bitset<N> orig;
unordered_map<bitset<N>, int> map;

int main() {
    int n, m, l, tmp;
    scanf("%d %d %d", &n, &m, &l);
    while (l--) {
        scanf("%d", &tmp);
        orig.set(tmp);
    }
    bitset<N> current;
    int answer = -1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &l);
        while (l--) {
            scanf("%d", &tmp);
            current.flip(tmp);
        }
        if ((current ^ orig).none()) {
            answer = i + 1;
            break;
        } else {
            if (map.find(current) == map.end()) {
                map[current] = i + 1;
            }
        }
    }
    if (answer == -1) {
        auto it = map.find(current ^ orig);
        if (it != map.end()) {
            answer = it->second + n;
        }
    }
    printf("%d\n", answer);
}