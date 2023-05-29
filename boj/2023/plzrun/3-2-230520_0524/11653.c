#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	int i = 2;
	while (N > 1) {
		for (; N % i; i++);
		printf("%d\n", i);
		N /= i;
	}
}