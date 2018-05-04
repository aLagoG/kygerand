#include <stdio.h>
#include <unordered_set>

typedef unsigned long long ull;

ull wlen = 10;
ull base = 26;
ull bpow = 5429503678976UL;
// char str[1000010];
char str[20];
int len;

inline bool clean(char c) {
    return c != 'C' && c != 'G';
}

inline char inv(char c) {
    return c == 'A' ? 'T' : 'A';
}

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    scanf("%c", &str[len]);
    while (t--) {
        len = 0;
        while (1) {
            if (scanf("%c", &str[len]) == EOF) {
                len--;
                break;
            };
            if (str[len++] == '\n') {
                len--;
                break;
            }
        }
        if (len < wlen) {
            printf("0\n");
            continue;
        }
        int start = 0;
        int cln = 0;
        for (int i = 0; i < len; i++) {
            if (cln == wlen) {
                start = i - wlen;
                break;
            }
            if (clean(str[i])) {
                cln++;
            } else {
                cln = 0;
            }
        }
        if (cln < wlen) {
            printf("0\n");
            continue;
        }
        ull cnt = 0;
        unordered_set<ull> seen;

        ull wh = 0, ih = 0;
        for (int i = start; i < start + wlen; i++) {
            wh = wh * base + str[i];
            ih = ih * base + inv(str[i]);
        }
        seen.insert(wh);

        unordered_set<ull> found;

        for (int i = start; i < len - wlen; i++) {
            char in = str[i + wlen];
            char out = str[i];

            wh -= out * bpow;
            wh = wh * base + in;

            ih -= inv(out) * bpow;
            ih = ih * base + inv(in);

            if (clean(in)) {
                cln++;
            } else {
                cln = 0;
            }

            if (cln >= 10) {
                if (seen.find(ih) != seen.end()) {
                    if (found.find(ih) != found.end()) {
                        cnt++;
                    } else {
                        cnt += 2;
                        found.insert(ih);
                    }
                } else {
                    seen.insert(wh);
                }
            }
        }
        printf("%llu\n", cnt);
    }
}