//2951
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

typedef long double ld;
unordered_set<string> st;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	string line;
	while(n--){
		cin >> line;
		// cout << line << "---\n";
		sort(line.begin(), line.end());
		// line+=".0";
		// cout << line << "\n";
		st.insert(line);
	}
	cout << st.size() << "\n";
}