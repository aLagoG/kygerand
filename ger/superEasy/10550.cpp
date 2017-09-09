//10550 - Combination Lock

#include <cstdio>
#include <stdlib.h>

using namespace std;

int main(){
	int i, f, s, t;
	while(1){
		scanf("%d %d %d %d", &i, &f, &s, &t);
		f = f-i < 0 ? 40 - f;
		f-=i; s-=i; t-=i;


		if(i==0 && f==0 && s==0 && t==0) break;
		printf("%d\n", (120 + /*(f>=i ? f-i : i + 40-f) +*/ (40-f) + (s>=f ? s-f : 40-f + s) + (t<=s ? s-t : s + 40-t) )*9);
	}
}