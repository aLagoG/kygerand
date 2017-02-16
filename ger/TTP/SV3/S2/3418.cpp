#include<cstdio>
using namespace std;

int main(){
	int vow[] = {0, 0, 0, 0, 0};
	char c;
	while(scanf("%c", &c) != EOF){
		if (c == 'A' || c == 'a'){
			vow[0] += 1;
		}
		if (c == 'E' || c == 'e'){
			vow[1] += 1;
		}
		if (c == 'I' || c == 'i'){
			vow[2] += 1;
		}
		if (c == 'O' || c == 'o'){
			vow[3] += 1;
		}
		if (c == 'U' || c == 'u'){
			vow[4] += 1;
		}
	}
	for(int i = 0; i <= 3; i++) printf("%d ", vow[i]);
	printf("%d", vow[4]);
}