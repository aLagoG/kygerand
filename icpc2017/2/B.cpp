#include <stdio.h>
#include <string.h>

// int ballons[101];

int main(){
	int n, b;
	while(scanf("%d %d", &n, &b), n || b){
		// memset(ballons, 0, sizeof ballons);
		int tmp;
		int sum = 0;
		for(int i=0;i<n;i++){
			// scanf(" %d ", &ballons[i]);
			scanf(" %d ", &tmp);
			sum += tmp;
		}
		printf("%d\n", b/sum);
	}

}