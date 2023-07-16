#include <cstdio>

char s[1000001];
int pi[1000001];

int main()
{
	scanf("%*d %s", s);

	int i = 1, j = 0;
	while (s[i]) {
		while (j && s[i] != s[j])
			j = pi[j];
		pi[++i] = s[i] == s[j] ? ++j : 0;
	}
	printf("%d", i - pi[i]);
}