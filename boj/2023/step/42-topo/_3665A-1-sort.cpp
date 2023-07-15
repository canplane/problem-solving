#include <bits/stdc++.h>

std::pair<int, int> p[501], _p[501];
bool sol()
{
	int N, M, i, x, y;
	
	scanf("%d", &N);
	for (i = 0; i < N; i++)	scanf("%d", &x), p[x] = _p[x] = { i, x };
	
	scanf("%d", &M);
	while (M--) {
		scanf("%d %d", &x, &y);
		if (!(_p[x].first < _p[y].first))	std::swap(x, y);
		p[x].first++, p[y].first--;
	}

	std::sort(p + 1, p + N + 1);

	if (p[1].first)	// 이 if는 사실 비둘기집의 원리에 의해 없어도 되는 코드
		return false;
	for (x = 2; x <= N; x++)
		if (p[x].first == p[x - 1].first)
			return false;

	for (x = 1; x <= N; x++)	printf("%d ", p[x].second);
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)	puts(sol() ? "" : "IMPOSSIBLE");
}