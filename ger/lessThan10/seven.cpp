#define ALL(x) x, x+sizeof x

#include<stdio.h>
#include<algorithm>

using namespace std;

char alphabet[] = {'A','B','C','D','E','F','G','H','I','J'};

void printer(){
	for(auto x: alphabet) printf("%c ", x);
	printf("\n");
}

int main(){
	do{
		printer();
	}while(next_permutation(ALL(alphabet)));
}
