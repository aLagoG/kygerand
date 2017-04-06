//3487
#include <stdio.h>
#include <string.h>
#include <queue>

#define N 10
#define S 9

using namespace std;

int bd[N][N];
bool rows[S][N];
bool cols[S][N];
bool squares[S][N];
int cnt;
typedef pair<int,int> pii;
queue<pii> q;

void printBoard(){
	for(int k=0;k<3;k++){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				printf("%d %d %d",bd[3*k+i][3*j],bd[3*k+i][3*j+1],bd[3*k+i][3*j+2]);
				if(j<2){
					printf(" | ");
				}
			}
			printf("\n");
		}
		if(k<2){
			printf("------+-------+------\n");
		}
	}
}

inline bool isValid(int n,int i,int j){
	return ! (rows[i][n]||cols[j][n]||squares[i/3*3+j/3][n]);
}

inline void ins(int n,int i,int j){
	bd[i][j] = n;
	rows[i][n] = 1;
	cols[j][n] = 1;
	squares[i/3* 3+j/3][n] = 1;
	cnt++;
}

inline void del(int i, int j){
	rows[i][bd[i][j]] = 0;
	cols[j][bd[i][j]] = 0;
	squares[i/3*3+j/3][bd[i][j]] = 0;
	bd[i][j] = 0;
	cnt--;
}

bool solve(int i, int j){
	if(cnt==81){
		return true;
	}
	while(bd[i][j]){
		if(++j==S){
			i++;
			j=0;
		}
	}
	for(int k=1;k<N;k++){
		if(isValid(k,i,j)){		
			ins(k,i,j);
			if(solve(i,j)) return true;
			del(i,j);
		}
	}
	return false;
}

int main(){
	char tmp;
	cnt = 0;
	memset(rows, 0, sizeof rows);
	memset(cols, 0, sizeof cols);
	memset(squares, 0, sizeof squares);
	for(int i=0;i<S;i++){
		for(int j=0;j<S;j++){
			scanf(" %c",&tmp);
			if(tmp=='|'||tmp=='-'||tmp=='+'){
				j--;
				continue;
			}
			if(tmp=='*'){
				bd[i][j]=0;
				q.push(pii(i,j));
				continue;
			}
			ins(tmp-'0',i,j);
		}
	}
	int i=0,j=0;
	while(bd[i][j]){
		if(++j==S){
			i++;
			j=0;
		}
	}
	solve(i,j);
	printBoard();
}