//462
#include <stdio.h>
#include <string.h>

using namespace std;

char hand[13][2];
char suits[] = {'S','H','D','C'};
int sCount[4];
int jqkBySuit[4][4];
bool stp[4];

int idx(char s){
	for(int i=0;i<4;i++){
		if(s==suits[i]){
			return i;
		}
	}
	return -1;
}

int main(){
	while(scanf("%c%c%*[ \n\t\r]", &hand[0][0], &hand[0][1])==2){
		memset(sCount, 0, sizeof sCount);
		memset(jqkBySuit, 0, sizeof jqkBySuit);
		memset(stp, 0, sizeof stp);
		int points = 0;
		int extraPoints = 0;
		for(int i=0;i<13;i++){
			if(i>0){
				if(scanf("%c%c%*[ \n\t\r]", &hand[i][0], &hand[i][1])!=2){
					return 0;
				}
			}
			switch(hand[i][0]){
			case('A'):
				points += 4;
				jqkBySuit[idx(hand[i][1])][3]++;
				break;
			case('K'):
				points += 3;
				jqkBySuit[idx(hand[i][1])][2]++;
				break;
			case('Q'):
				points += 2;
				jqkBySuit[idx(hand[i][1])][1]++;
				break;
			case('J'):
				points += 1;
				jqkBySuit[idx(hand[i][1])][0]++;
				break;
			}
			switch(hand[i][1]){
			case('S'):
				sCount[0]++;
				break;
			case('H'):
				sCount[1]++;
				break;
			case('D'):
				sCount[2]++;
				break;
			case('C'):
				sCount[3]++;
				break;
			}
		}
		for(int i=0;i<4;i++){
			if(jqkBySuit[i][3]>0){
				stp[i]=true;
			}
			if(jqkBySuit[i][2]>0){
				if(sCount[i]<2){
					points--;
				}else{
					stp[i] = true;
				}
			}
			if(sCount[i]<3&&jqkBySuit[i][1]>0){
				if(sCount[i]<3){
					points -= jqkBySuit[i][1];
				}else{
					stp[i] = true;
				}
			}
			if(sCount[i]<4&&jqkBySuit[i][0]>0){
				points -= jqkBySuit[i][0];
			}
			if(sCount[i]==2){
				extraPoints++;
			}
			if(sCount[i]==1){
				extraPoints+=2;
			}
			if(sCount[i]==0){
				extraPoints+=2;
			}
		}
		bool s = true;
		for(int i=0;i<4;i++){
			if(!stp[i]){
				s = false;
				break;
			}
		}
		if(points+extraPoints<14){
			printf("PASS\n");
		}else if(points>=16&&s){
			printf("BID NO-TRUMP\n");
		}else{
			int p = 0;
			int k = 0;
			for(int i=0;i<4;i++){
				if(sCount[i]>p){
					p = sCount[i];
					k = i;
				}
			}
			printf("BID %c\n", suits[k]);
		}
	}
}
