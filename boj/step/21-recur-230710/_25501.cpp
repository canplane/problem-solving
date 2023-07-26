#include <cstdio>
#include <cstring>
#include <cmath>

int isPalindrome(const char *s)
{
	int len = strlen(s);
	int i = 0;
	for (; i <= len / 2; i++) {
		if (s[i] != s[(len - 1) - i]) {
			return -(i + 1);
		}
	}
	return i;	// for문 실행 수와 i는 같음 (마지막에 i++ 하니까)
}

char s[1001];

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		int ret = isPalindrome(s);
		printf("%d %d\n", ret > 0, abs(ret));
	}
}