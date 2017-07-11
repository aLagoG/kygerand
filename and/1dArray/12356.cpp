#include <stdio.h>
#include <set>

using namespace std;

int main() {
    int s, b, l, r;
    while (scanf("%d %d", &s, &b), b || s) {
        set<int> st;
        for (int i = 1; i <= s; i++) {
            st.insert(st.end(), i);
        }
        while (b--) {
            scanf("%d %d", &l, &r);
            st.erase(st.find(l), st.upper_bound(r));

            if (st.size() == 0) {
                printf("* *\n");
                continue;
            }
            set<int>::iterator it = st.upper_bound(r);
            if (it == st.end()) {
                printf("%d *\n", *--it);
            } else if (it == st.begin()) {
                printf("* %d\n", *it);
            } else {
                printf("%d %d\n", *--it, *it);
            }
        }
        printf("-\n");
    }
}