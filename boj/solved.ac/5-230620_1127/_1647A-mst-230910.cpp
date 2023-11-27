// BOJ 1657 G4 도시 분할 계획
// idea: MST에서 제일 큰 엣지 1개 빼기!
// 태그 안봤으면 발상 생각 전혀 못했을 듯

using namespace std;
#include <bits/stdc++.h>

int dj[100001];
void dj_init()
{
	for (int u = 1; u <= 100000; u++) {
		dj[u] = u;
	}
}
int dj_find(int u)
{
	int r = u;
	while (dj[r] != r) {
		r = dj[r];
	}
	int t;
	while (dj[u] != u) {
		t = dj[u];
		dj[u] = r;
		u = t;
	}
	return r;
}
void dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	dj[rv] = ru;
}

int main()
{
	int N, M;
	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		pq.push({ w, u, v });
	}

	dj_init();

	int cnt = 0, ans = 0;
	while (cnt < N - 2) {
		auto [w, u, v] = pq.top(); pq.pop();
		if (dj_find(u) != dj_find(v)) {
			++cnt, ans += w;
			dj_union(u, v);
		}
	}
	printf("%d", ans);
}