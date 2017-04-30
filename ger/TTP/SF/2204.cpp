#include <cstdio>
using namespace std;

int main(){
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 2; i <= n; i++){
			printf("%d ",i);
		}
		printf("1\n");
	}
}