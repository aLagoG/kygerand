#include <stdio.h>
#include <string.h>

bool nums[32];

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i=size-1;i>=0;i--)
    {
        for (j=7;j>=0;j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}

void isIt(){
	for(int i=0;i<32;i++){
		if(!nums[i]){
			printf("no\n");
			return;
		}
	}
	printf("yes\n");
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		unsigned int n;
		scanf("%u",&n);
		memset(nums,0,sizeof nums);
		char sum = 0;
		// printf("----%d----\n",n);
		// printBits(sizeof n,&n);
		for(int i=31;i>26;i--){
			sum |= ((n>>i)&1)<<i-27;
		}
		// printBits(sizeof sum, &sum);
		// printf("%u\n",sum);
		nums[sum] = 1;
		for(int i=26;i>=0;i--){
			sum &= 15;
			sum <<= 1;
			sum |= (n>>i)&1;
			nums[sum] = 1;
			// printBits(sizeof sum, &sum);
			// printf("%u\n",sum);
		}
		for(int i=31;i>=28;i--){
			sum &= 15;
			sum <<= 1;
			sum |= (n>>i)&1;
			nums[sum] = 1;
			// printBits(sizeof sum, &sum);
			// printf("%u\n",sum);
		}
		isIt();
	}
}