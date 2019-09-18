#include <stdio.h>
#include <algorithm>

using namespace std;

typedef unsigned long ulong;

const int N = 1e5 + 5;
ulong arr[N] = {};

int main() {
    ulong n, c, t;
    ulong sum = 0;
    scanf("%lu %lu %lu", &n, &c, &t);
    for (int i = 0; i < n; ++i) {
        scanf("%lu", &arr[i]);
        sum += arr[i];
    }
    float avg = sum * 1.0f / c;
    ulong _max = 0, current = 0, count = 1, overall = 0;
    for (int i = 0; i < n; ++i) {
        if (current + arr[i] <= avg || current + arr[i] <= _max ||
            current + arr[i] <= sum - overall * 1.0f / (c - count)) {
            current += arr[i];
        } else {
            if (current > _max) {
                _max = current;
            }
            current = arr[i];
            ++count;
        }
        overall += arr[i];
    }
    if (current > _max) {
        _max = current;
    }
    ulong val = _max / t;
    if (_max % t != 0) {
        ++val;
    }
    printf("%lu\n", val);
}
