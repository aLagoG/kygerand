//2721
#include <stdio.h>
#include <algorithm>

using namespace std;

int cards[100];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&cards[i]);
	}
	bool ch = false;
	do{
		ch = false;
		sort(cards,cards+n);
		for(int i=1;i<n;i++){
			if(cards[i]>cards[0]){
				ch = true;
				int tmp = cards[i]%cards[0];
				if(!tmp){
					tmp = cards[0];
				}
				cards[i] = tmp;
			}
			
		}
	}while(ch);
	int sum = 0;
	for(int i=0;i<n;i++){
		sum+= cards[i];
	}
	printf("%d\n",sum);
}