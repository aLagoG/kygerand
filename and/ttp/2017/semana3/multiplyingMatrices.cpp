//2690
#include <stdio.h>

int n,m,r,c;

int a[100][100];
int b[100][100];
int res[100][100];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	scanf("%d %d",&r,&c);
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&b[i][j]);
		}
	}
	// printf("%d %d %d %d\n",n,m,r,c);
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		printf("%d ",a[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	// for(int i=0;i<r;i++){
	// 	for(int j=0;j<c;j++){
	// 		printf("%d ",b[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");
	if(m!=r){
		printf("The matrices can not be multiplied\n");
		return 0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<c;j++){
			int sum =0;
			for(int k=0;k<m;k++){
				sum+=a[i][k]*b[k][j];
			}
			res[i][j] = sum;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<c;j++){
			printf("%d",res[i][j]);
			if(j+1<c){
				printf(" ");
			}
		}
		printf("\n");
	}
}