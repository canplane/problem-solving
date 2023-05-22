#include <cstdio>

char s[100001];
int ans, bias;

int main()
{
	scanf("%s", s);
	for (int i = 0; s[i]; i++) {
		if (s[i] == '(') {
			bias += 1;
		}
		else {
			bias -= 1;
			if (i > 0 && s[i - 1] == '(')
				ans += bias;
			else
				ans += 1;
		}
	}
	printf("%d\n", ans);
}