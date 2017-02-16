#include <cstdio>

using namespace std;

int main(){
	int a, b, c;
	scanf("%d", a);
	scanf("%d", b);
	scanf("%d", c);

	if(a+b+c != 180){
		printf("Error");
	}else if((a == b) && (a == c) && (b == c)){
		printf("Equilateral");
	}else if((a != b) && (a != c) && (b != c)){
		printf("Scalene");
	}else{
		printf("Isoceles");
	}

	return 0;
}