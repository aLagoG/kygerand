const int MAX = 1000;

int f[MAX];

int fib(int n) {
    if (n == 0) {
        return 0;
    }

    if (f[n]) {
        return f[n];
    }

    int k = (n & 1) ? (n + 1) >> 1 : n >> 1;

    f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : ((fib(k - 1) << 1) + fib(k)) * fib(k);

    return f[n];
}

int main() {
    f[1] = f[2] = 1;
}
