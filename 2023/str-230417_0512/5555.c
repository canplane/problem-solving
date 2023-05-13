#include <stdio.h>
#include <string.h>

char key[11], s[20];
int N, ret;

int main()
{
	scanf("%s %*s", key);
	while (~scanf("%s", s)) {
		memcpy(s + strlen(s), s, strlen(key) - 1);
		ret += !!strstr(s, key);
	}
	printf("%d", ret);
}