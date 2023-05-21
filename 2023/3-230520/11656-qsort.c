#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>

char s[1001];
int n;

#define		T		char *
T A[1001];
int _cmp(const void *a, const void *b) {
	return strcmp(*(T *)a, *(T *)b);
}

int main()
{
	scanf("%s", s);
	for (n = 0; s[n]; n++)
		A[n] = s + n;
	A[n] = s + n;

	qsort(A, n, sizeof(*A), _cmp);

	for (n = 0; *A[n]; n++)
		printf("%s\n", A[n]);
}