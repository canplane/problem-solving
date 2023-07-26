using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

#define MAX_N 100000

int N;
pair<int, int> X[3][MAX_N];
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq[3];

int parent[MAX_N];
void dj_init()
{
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}
}
int dj_find(int u)
{
	int r = u;
	while (parent[r] != r) {
		r = parent[r];
	}
	int t;
	while (parent[u] != u) {
		t = parent[u];
		parent[u] = r;
		u = t;
	}
	return r;
}
void dj_union(int a, int b)
{
	int ra = dj_find(a), rb = dj_find(b);
	parent[rb] = ra;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			int x;
			scanf("%d", &x);
			X[j][i] = { x, i };
		}
	}
	for (int j = 0; j < 3; j++) {
		sort(X[j], X[j] + N);
	}

	for (int j = 0; j < 3; j++) {
		for (int i = 1; i < N; i++) {
			int d = X[j][i].first - X[j][i - 1].first;
			int a = X[j][i - 1].second, b = X[j][i].second;
			if (a > b) {
				swap(a, b);
			}
			pq[j].push({ d, { a, b } });
		}
	}

	int ans = 0;
	dj_init();
	for (int k = 0; k < N - 1; k++) {
		for (int j = 0; j < 3; j++) {
			while (true) {
				auto [a, b] = pq[j].top().second;
				if (dj_find(a) != dj_find(b))	break;
				pq[j].pop();
			}
		}
		pair<int, pair<int, int>> candi[3];
		for (int j = 0; j < 3; j++) {
			candi[j] = pq[j].top();
		}
		sort(candi, candi + 3);
		auto [d, p] = candi[0]; auto [a, b] = p;
		dj_union(a, b);
		ans += d;
	}
	printf("%d", ans);
}