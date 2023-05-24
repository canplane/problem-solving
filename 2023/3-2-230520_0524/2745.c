#include <stdio.h>
#include <stdlib.h>

char N[1000000];
int B;

int main()
{
	scanf("%s %d", N, &B);
	printf("%ld", strtol(N, NULL, B));
}