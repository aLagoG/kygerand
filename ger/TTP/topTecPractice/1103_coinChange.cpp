#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int criba[7490];
	int coins[5] = {1,5,10,25,50};
	int n;
	criba[0] = 1;
	for(int i = 0; i<7490; i++) criba[i]=1;
	for(int& coin: coins)
		for(int i = coin; i <= 7490; i++) criba[i] = criba[i]+criba[i-coin];
	while(scanf("%d", &n) != EOF){
		printf("%d\n", criba[n]);
	}
}