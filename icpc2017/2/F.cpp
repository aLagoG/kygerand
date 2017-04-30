#include <iostream>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;

#define MAX 26

inline char cmp(char a, int f) {
	return a + f > 'z' ? ((a + f) % 'z') + 'a' - 1 : a + f;

}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s;
	int t, f, count, index;
	bool flag;
	cin >> t;
	while (t--) {
		cin >> s >> f;
		int n = s.length();
		int *lis, i, j, max = 0;
		lis = (int*) malloc ( sizeof( int ) * n );
		for (i = 0; i < n; i++ )
			lis[i] = 1;
		for (i = 1; i < n; i++ )
			for (j = 0; j < i; j++ )
				if ( s[i] >= cmp(s[j], f) && lis[i] < lis[j] + 1)
					lis[i] = lis[j] + 1;
		for (i = 0; i < n; i++ )
			if (max < lis[i])
				max = lis[i];
		free(lis);
		cout << max << '\n';
	}
}