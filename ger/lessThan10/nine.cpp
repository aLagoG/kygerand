#include<stdio.h>
#include<vector>

using namespace std;

int numberize(char c){ return  c < 58 ? c-48 : c-55; }
int digitize(char c){ return  c < 9 ? c+48 : c+55; }

int main(){
	int len, bx, by;

	printf("digit length>\n");
	scanf("%d", &len);

	printf("number>\n");
	char a[len];
	scanf("%s", a);

	printf("base x base y>\n");
	scanf("%d %d", &bx, &by);
	
	//from digits to number
	int n = 0;
	for(auto d: a) n = bx * n + numberize(d); 

	//printf("%d\n", n);

	//from number to digits.
	vector<char> res;
	while(n > 0){
		res.insert(res.begin(), digitize(n % by));
		n = n/by;
	}

	for(auto c: res) printf("%c", c);
	printf("\n");
}