/*
	* 틀린 이유: idea
		n등분해서 반올림하는 아이디어는 {1 2 3 10}, C = 4 같을 때 가로막힌다!
*/

using namespace std;
#include <cstdio>
#include <algorithm>

long x[200000], c[200000];
int N, C;

int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%ld", &x[i]);
	sort(x, x + N);

	for (int i = 0; i < C; i++) {
		c[i] = x[0] + i * (x[N - 1] - x[0]) / (C - 1);
	}

	for (int i = 0; i < C; i++)
		printf("%ld ", c[i]);
	puts("");

	for (int i = 1; i < C - 1; i++) {
		auto it = upper_bound(x, x + N, c[i]);
		long dl = c[i] - *(it - 1), dr = *it - c[i];
		c[i] = (dl <= dr) ? *(it - 1) : *it;
		//if (c[i - 1] == c[i])
		///	c[i] = *it;
	}

	for (int i = 0; i < C; i++)
		printf("%ld ", c[i]);
	puts("");

	long ans = x[N - 1] - x[0];
	for (int i = 1; i < C; i++)
		ans = min(ans, c[i] - c[i - 1]);
	printf("%ld", ans);
}