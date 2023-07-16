// S의 최소 주기는 S의 길이에서 마지막 fail 값을 뺀 값과 동일하다.
// 증명: https://www.acmicpc.net/board/view/122146

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