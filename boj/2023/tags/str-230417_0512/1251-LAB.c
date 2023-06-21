#include <stdio.h>
#include <string.h>

void reverse(char *p, char *q)
{
	char tmp;
	for (q--; p < q; p++, q--)
		tmp = *p, *p = *q, *q = tmp;
}

#define MAXSZ 50
char X[MAXSZ + 1], res[MAXSZ + 1], s[MAXSZ + 1];

int main()
{
	scanf("%s", X);
	int len = strlen(X);

	for (int i = 1; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			strncpy(s, X, MAXSZ);
			reverse(s, s + i), reverse(s + i, s + j), reverse(s + j, s + len);
			if (!res[0] || strcmp(res, s) > 0)
				strncpy(res, s, MAXSZ);
		}
	}
	printf("%s", res);
}