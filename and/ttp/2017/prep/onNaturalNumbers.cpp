//2827
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <vector>

typedef unsigned long long ll;
using namespace std;

int main() {
    ll n;
    vector<ll> fib(86);
    fib[0] = 1;
    fib[1] = 2;
    for (int i = 2; i<86; i++) {
	fib[i] = fib[i - 1] + fib[i - 2];
	//printf("%llu\n",fib[i]);
	}
    while (scanf("%llu", &n) != EOF) {
	//printf("%llu\n",n);
	int idx = lower_bound(fib.begin(), fib.end(), n) - fib.begin();
	printf("%llu = ", n);
	if (fib[idx] == n) {
	    printf("%llu\n", n);
	    continue;
	}
	idx--;
	stack<ll> stk;
	ll left = n;
	while (idx >= 0 && left>0) {
	     if (left >= fib[idx]) {
		left -= fib[idx];
		stk.push(fib[idx--]);
	    }
	    idx--;
	}
	while (stk.size()>1) {
	    printf("%llu + ", stk.top());
	    stk.pop();
	}
	printf("%llu\n", stk.top());
    }
}
