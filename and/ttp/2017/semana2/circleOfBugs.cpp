//1889
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int cnt[101];

int main(){
	int n;
	double pi2 = 2*(2*acos(0));
	memset(cnt,0,sizeof(cnt));
	scanf("%d",&n);
	while(n--){
		int s;
		scanf("%d",&s);
		cnt[s]++;
	}
	double sum = 0;
	int count =0;
	for(int i=100;i>0;i--){
		if(cnt[i]){
			while(cnt[i]--&&count<10){
				count++;
				sum += i;
			}
		}
	}
	printf("%.4lf\n",sum/pi2);
}