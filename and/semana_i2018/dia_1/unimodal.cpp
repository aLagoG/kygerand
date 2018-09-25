#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    bool unimodal = true, hack = true, skip_middle = false;
    int last, current;
    scanf("%d", &last);
    int i;
    for (i = 1; i < n && hack; i++) {
        scanf("%d", &current);
        if (current == last) {
            hack = false;
        } else if (current < last) {
            hack = false;
            skip_middle = true;
        }
        last = current;
    }
    if (!skip_middle) hack = true;
    for (; i < n && hack; i++) {
        scanf("%d", &current);
        if (current > last) {
            unimodal = false;
            hack = false;
        } else if (current < last) {
            hack = false;
        }
        last = current;
    }
    for (; i < n && unimodal; i++) {
        scanf("%d", &current);
        if (current >= last) {
            unimodal = false;
        }
        last = current;
    }
    printf(unimodal ? "YES\n" : "NO\n");
}