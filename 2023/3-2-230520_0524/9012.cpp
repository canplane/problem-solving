#include <cstdio>

int N;
char s[100];

int check()
{
	int bias = 0;
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			bias += 1;
		}
		else {
			if (bias == 0)
				return 0;
			bias -= 1;
		}
	}
	return bias == 0;
}

int main()
{
	scanf("%d", &N);
	while (N--) {
		scanf("%s", s);
		printf("%s\n", check() ? "YES" : "NO");
	}
}