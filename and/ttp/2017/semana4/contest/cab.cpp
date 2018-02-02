//2701
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

string word;
vector<char> w1;
vector<char> w2;

int main(){
	char c;
	double sum = 0;
	while(scanf("%c",&c)!=EOF&&c!='\n'){
		sum+=c-64;
	}
	while(sum>0){
		w1.push_back((int)min(26.0,ceil(sum/2)));
		sum -= w1.back();
		if(sum<=0){
			break;
		}
		w2.push_back((int)min(26.0,sum));
		sum -= w2.back();
	}
	for(auto i: w2){
		printf("%c",i+64);
	}
	printf(" ");
	for(auto i: w1){
		printf("%c",i+64);
	}
}