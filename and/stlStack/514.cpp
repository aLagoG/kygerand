#include <stdio.h>
#include <stack>

using namespace std;

stack<int> st;
int current = 1;
int needed;

bool handleCart() {
    if (needed < current) {
        if (st.top() != needed) {
            return false;
        } else {
            st.pop();
        }
    } else {
        while (needed > current) {
            st.push(current++);
        }
        if (needed == current) {
            current++;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (scanf("%d", &n), n) {
        while (!st.empty()) {
            st.pop();
        }
        while (scanf("%d", &needed), needed) {
            current = 1;
            bool valid = handleCart();
            for (int i = 1; i < n; i++) {
                scanf("%d", &needed);
                if (valid) {
                    valid = handleCart();
                }
            }
            printf(valid ? "Yes\n" : "No\n");
        }
        printf("\n");
    }
}