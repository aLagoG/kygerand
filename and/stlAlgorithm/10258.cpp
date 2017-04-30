#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int cont[101][10];
bool sub[101][10];

typedef pair<int, pair<int, int> > pp;

int main(){
	int nt;
	char newLine;
	scanf("%d",&nt);
	while(nt--){
		int c, p, t;
		char l;
		memset(cont,0,sizeof cont);
		memset(sub,0,sizeof sub);
		while(scanf(" %d %d %d %c%c",&c,&p,&t,&l,&newLine)!=EOF){
			if(!sub[c][p]){
				switch(l){
					case 'C':
						cont[c][p] += t;
						sub[c][p] = 1;
						break;
					case 'I':
						cont[c][p] += 20;
						break;
				}
			}
			sub[c][0] = 1;
			if(scanf("%[\n ]",&newLine)){
				break;
			}
		}
		vector<pp> v;
		int sumP, sumT;
		for(int i=1;i<101;i++){
			sumP=0;
			sumT=0;
			if(sub[i][0]){
				for(int j=1;j<10;j++){
					if(sub[i][j]){
						sumP++;
						sumT += cont[i][j];
					}
				}
				v.push_back(pp(i,pair<int,int>(sumP,sumT)));
			}
		}
		sort(v.begin(), v.end(), [](const pp &lhs, const pp &rhs){
			if(lhs.second.first == rhs.second.first){
				if(lhs.second.second == rhs.second.second){
					return lhs.first < rhs.first;
				}
				return lhs.second.second < rhs.second.second;
			}
			return lhs.second.first > rhs.second.first;
		});
		for(pp i : v){
			printf("%d %d %d\n", i.first, i.second.first, i.second.second);
		}
		if(nt){
			printf("\n");
		}
	}
}