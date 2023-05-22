#include <cstdio>
#include <cstring>

char s[100001];
int cnt[26];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(cnt, 0, sizeof(cnt));
		scanf("%s", s);
		for (int i = 0; s[i]; i++) {
			if (!(++cnt[s[i] - 'A'] % 3)) {
				if (s[i] != s[i + 1])   goto FAKE;
				i++;
			}
		}
		puts("OK");
		continue;
FAKE:	puts("FAKE");
	}
}