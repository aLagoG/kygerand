#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
	int nums[20]; for (int i = 0; i < 20; i++) nums[i] = i;
	int max = 1<<20;
	for (int i = 0; i < max; i++) {
		for(int j=0;j<20;j++) {
			if (i&(1<<j)) {
				printf("%d ", nums[j]);
			}
		}
		printf("\n");
	}
}