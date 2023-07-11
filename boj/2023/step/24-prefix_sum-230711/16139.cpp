#include <cstdio>

char s[200002];
int S[200001][26];

int main()
{
	scanf("%s", s + 1);
	for (int i = 1; s[i]; i++) {
		for (int j = 0; j < 26; j++) {
			S[i][j] = S[i - 1][j];
			if (s[i] == 'a' + j) {
				S[i][j] += 1;
			}
		}
	}

	int T;
	scanf("%d", &T);
	while (T--) {
		char a;
		int l, r;
		scanf(" %c %d %d", &a, &l, &r);
		printf("%d\n", S[r + 1][a - 'a'] - S[l][a - 'a']);
	}
}