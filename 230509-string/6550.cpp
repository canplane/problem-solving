#include <cstdio>

char s[100001], t[100001];

int main()
{
	while (~scanf("%s %s", s, t)) {
		int i = 0, j = 0;
		for (; t[j]; j++)
			if (s[i] == t[j])	i++;
		puts(s[i] ? "No" : "Yes");
	}
}