#include <stdio.h>

char s[101];
int d[26];

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		d[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		printf("%d ", d[i]);
	}
}