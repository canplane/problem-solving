#include <stdio.h>
#include <string.h>

char s[101];
int d[26];
char c;

int main()
{
	memset(d, -1, sizeof(d));

	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		c = s[i] - 'a';
		if (!~d[c])
			d[c] = i;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", d[i]);
	}
}