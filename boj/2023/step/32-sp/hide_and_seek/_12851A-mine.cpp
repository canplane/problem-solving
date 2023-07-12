using namespace std;
#include <cstdio>
#include <queue>

#define INF ((1L << 31) - 1)

int dist[200001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	for (int i = 0; i <= 200000; i++) {
		dist[i] = INF;
	}

	int ans = INF, cnt = 0;
	queue<int> q;
	dist[N] = 0, q.push(N);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == K) {
			ans = dist[u], cnt++;
			continue;
		}
		int v;
		if ((v = 2 * u) <= 200000 && dist[u] + 1 <= dist[v]) {
			dist[v] = dist[u] + 1, q.push(v);
		}
		if ((v = u + 1) <= 200000 && dist[u] + 1 <= dist[v]) {
			dist[v] = dist[u] + 1, q.push(v);
		}
		if ((v = u - 1) >= 0 && dist[u] + 1 <= dist[v]) {
			dist[v] = dist[u] + 1, q.push(v);
		}
	}
	printf("%d\n%d", ans, cnt);
}