//2191
#include <stdio.h>

#define min(x,y) (x>y?y:x)

int mp[100][100];
int ian[100][100];
int n,m;

// void pr(int arr[100][100]){
// 	for(int i=0;i<n;i++){
// 		for(int j=0;j<m;j++){
// 			printf("%d ",arr[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

void fix(int i,int j, int k, int z){
	if(ian[i][j]+mp[k][z]<ian[k][z]){
		ian[k][z] = ian[i][j]+mp[k][z];
		if(z+1<m&&ian[k][z]<ian[k][z+1]){
				fix(k,z,k,z+1);
		}
		if(z>1&&ian[k][z]<ian[k][z-1]){
				fix(k,z,k,z-1);
		}
		if(k>=1&&ian[k][z]<ian[k-1][z]){
			fix(k,z,k-1,z);
		}
		if(k+1<n&&ian[k][z]<ian[k+1][z]){
			fix(k,z,k+1,z);
		}
	}
}

int main(){
	scanf("%d %d",&n, &m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	for(int i=0;i<n;i++){
		ian[i][m-1] = mp[i][m-1];
	}

	for(int j=m-2;j>=0;j--){
		ian[0][j] = ian[0][j+1]+mp[0][j];
		// pr(ian);
		for(int i=1;i<n;i++){
			ian[i][j] = min(ian[i][j+1],ian[i-1][j])+mp[i][j];
		}
		// printf("---\n");
		// pr(ian);
		// printf("\n");
		for(int i=n-2;i>=0;i--){
			ian[i][j] = min(ian[i][j],ian[i+1][j]+mp[i][j]);
		}
		for(int i=0;i<n;i++){
			if(ian[i][j]<ian[i][j+1]){
				fix(i,j,i,j+1);
			}
			if(i>=1&&ian[i][j]<ian[i-1][j]){
				fix(i,j,i-1,j);
			}
			if(i+1<n&&ian[i][j]<ian[i+1][j]){
				fix(i,j,i+1,j);
			}
		}
	}
	// printf("\n");
	// pr(mp);
	// printf("\n");
	// pr(ian);
	int min = (1U<<31)-1;
	for(int i=0;i<n;i++){
		if(ian[i][0]<min){
			min = ian[i][0];
		}
	}
	printf("%d\n",min);
}