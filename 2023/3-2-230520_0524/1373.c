#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char N[10000000], token[4];

int main()
{
	scanf("%s", N);
	int len = strlen(N);

	char *p = N;
	if (len % 3) {
		strncpy(token, p, len % 3);
		printf("%lo", strtol(token, NULL, 2));
		p += len % 3;
	}
	while (*p) {
		strncpy(token, p, 3);
		printf("%lo", strtol(token, NULL, 2));
		p += 3;
	}
}