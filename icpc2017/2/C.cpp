#include <stdio.h>
#include <cmath>

typedef unsigned long long ll;
typedef struct {
	ll x;
	ll h;
	int l;
	int r;
} st;

st arr[500101];

inline double d(st a ,st b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.h-b.h)*(a.h-b.h));
}

int main() {
	int n;
	scanf("%d", &n);
	ll x, b;
	scanf("%llu %llu", &x, &b);
	st f;
	f.x = x;
	f.h = b;
	f.l = 0;
	arr[0] = f;
	for (int i = 1; i <= n; i++) {
		scanf("%llu %llu", &x, &b);
		st var;
		var.x = x;
		var.h = b;
		int tmp = i - 1;
		while (arr[tmp].h <= b) {
			tmp = arr[tmp].l;
		}
		var.l = tmp;
		arr[i] = var;
	}
	scanf("%llu %llu", &x, &b);
	st l;
	l.x = x;
	l.h = b;
	l.r = n+1;
	arr[n+1] = l;

	for (int i = n; i > 0; i--) {
		ll b = arr[i].h;
		int tmp = i + 1;
		while (arr[tmp].h <= b) {
			tmp = arr[tmp].r;
		}
		arr[i].r = tmp;
	}

	for (int i = 1; i < n + 1; i++) {
		printf("%d %d %.4lf %.4lf\n", arr[i].l, arr[i].r, d(arr[i],arr[arr[i].l]), d(arr[i],arr[arr[i].r]));
	}
}