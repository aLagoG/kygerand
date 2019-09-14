#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

const int MAXN = 1e5;

int n;
char num[5];

int main() {
    scanf("%d", &n);
    int l, c, r, m;
    while (n--) {
        scanf(" 0.%s", &num);
        l = strlen(num);
        m = 1;
        while (l - 1 >= 0 && num[l - 1] == '0') {
            num[--l] = 0;
        }
        for (c = 0; c < l && num[c] == '0'; ++c) {
        }
        for(int i=0;i<l;++i){
            m*=10;
        }
        r = atoi(&num[c]);
        for (int i = 1; i < MAXN; i++) {
            if (i * r / m * m == i * r) {
                printf("%d\n", i);
                break;
            }
        }
    }
}