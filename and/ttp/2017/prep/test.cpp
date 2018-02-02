#include <stdio.h>
int main() {
	printf("%lu\n", sizeof(float));
    printf("%lu\n", sizeof(double)); // some compilers print 8
    printf("%lu\n", sizeof(long double)); // some compilers print 16
    return 0;
}
