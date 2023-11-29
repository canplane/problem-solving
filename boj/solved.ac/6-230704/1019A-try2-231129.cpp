// BOJ 1019 G1 책 페이지
// 최백준님 풀이 (https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1019)

#include <cstdio>

long C[10];

void calc(int n, int w)
{
	while (n > 0)
		C[n % 10] += w, n /= 10;
}
void cnt(int l, int r, int w)
{
	while (l != r && l % 10 != 0)
		calc(l++, w);
	while (l != r && r % 10 != 9)
		calc(r--, w);
	if (l == r) {
		calc(l, w);
		return;
	}

	l /= 10, r /= 10;
	int k = r - l + 1;
	for (int i = 0; i < 10; i++)
		C[i] += k * w;
	cnt(l, r, 10 * w);
}

int main()
{
	int N;
	scanf("%d", &N);

	cnt(1, N, 1);
	for (long e : C)
		printf("%ld ", e);
}