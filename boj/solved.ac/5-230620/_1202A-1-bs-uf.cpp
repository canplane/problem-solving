// BOJ 1202 G2 보석 도둑
// [2 hours...] 이분 탐색 + 유니언파인드로 다음 슬롯 바로 접근
// 유니언 파인드 일부러 구현해야 해서 이게 더 좋지 않은 듯. 힙보단 다소 빠름

using namespace std;
#include <bits/stdc++.h>

int N, K;
pair<int, int> A[300000];
int C[300000];

int dj[300001];
void dj_init()
{
	for (int u = 0; u <= K; u++)
		dj[u] = u;
}
int dj_find(int u)
{
	int r = u;
	while (dj[r] != r)
		r = dj[r];
	int t;
	while (dj[u] != u)
		t = dj[u], dj[u] = r, u = t;
	return u;
}
void dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	dj[rv] = ru;
}

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int m, v;
		scanf("%d %d", &m, &v);
		A[i] = { v, m };
	}
	for (int i = 0; i < K; i++) {
		scanf("%d", &C[i]);
	}

	sort(A, A + N, greater()), sort(C, C + K);

	long ans = 0;
	dj_init();
	for (int i = 0; i < N; i++) {
		auto [v, m] = A[i];
		int j = dj_find(lower_bound(C, C + K, m) - C);
		if (j != K)
			ans += v, dj_union(j + 1, j);
	}
	printf("%ld", ans);
}