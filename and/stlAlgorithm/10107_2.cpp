#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

priority_queue<long, vector<long>, greater<long>> big;
priority_queue<long> small;
int balance = 0;
long median = 0;

int main() {
    long n;
    while (scanf("%ld", &n) != EOF) {
        switch (balance) {
            case 0:
                if (n < median) {
                    small.push(n);
                    median = small.top();
                    balance = -1;
                } else {
                    big.push(n);
                    median = big.top();
                    balance = +1;
                }
                break;
            case 1:
                if (n <= median) {
                    small.push(n);
                } else {
                    big.push(n);
                    small.push(big.top());
                    big.pop();
                }
                balance = 0;
                median = (small.top() + big.top()) >> 1;
                break;
            case -1:
                if (n >= median) {
                    big.push(n);
                } else {
                    small.push(n);
                    big.push(small.top());
                    small.pop();
                }
                balance = 0;
                median = (small.top() + big.top()) >> 1;
                break;
        }
        printf("%ld\n", median);
    }
}