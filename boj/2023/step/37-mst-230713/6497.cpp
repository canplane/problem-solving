using namespace std;
#include <cstdio>
#include <queue>
#include <utility>

int dj[200000];
void dj_init(int n)
{
	for (int i = 0; i < n; i++) {
		dj[i] = i;
	}
}
int dj_find(int u)
{
	int r = u, t;
	while (dj[r] != r) {
		r = dj[r];
	}
	while (dj[u] != u) {
		t = dj[u], dj[u] = r, u = t;
	}
	return r;
}
bool dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	dj[rv] = ru;
	return ru != rv;
}

int main()
{
	while (true) {
		int M, N;
		scanf("%d %d", &M, &N);
		if (M == 0 && N == 0) {
			break;
		}

		int tot = 0, cnt = 0;
		priority_queue<pair<int, pair<int, int>>> pq;
		while (N--) {
			int x, y, z;
			scanf("%d %d %d", &x, &y, &z);
			tot += z;
			pq.push({ -z, { x, y } });
		}

		dj_init(M);
		while (!pq.empty()) {
			auto [cost, p] = pq.top(); pq.pop();
			auto [x, y] = p;
			if (dj_union(x, y)) {
				cnt += -cost;
			}
		}
		printf("%d\n", tot - cnt);
	}
}