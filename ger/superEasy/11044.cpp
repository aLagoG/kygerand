#include <cstdio>

using namespace std;

int main(){
	int t, w, h;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &w, &h); printf("%d\n", (w/3) * (h/3));
	}
}