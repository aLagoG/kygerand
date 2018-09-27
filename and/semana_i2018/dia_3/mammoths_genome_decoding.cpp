#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int n;
char s[256];
char l[] = {'A', 'C', 'G', 'T'};
map<char, int> m;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(" %c", &s[i]);
        m[s[i]]++;
    }
    int min = 0;
    for (auto x : l) {
        min = max(m[x], min);
    }
    if (n % 4 || n / 4 < min) {
        printf("===\n");
        return 0;
    }
    int goal = n / 4;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != '?') {
            printf("%c", s[i]);
            continue;
        }
        while (m[l[idx]] >= goal) {
            idx++;
        }
        printf("%c", l[idx]);
        m[l[idx]]++;
    }
}