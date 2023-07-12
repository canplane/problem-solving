// 숨바꼭질 5
// 홀짝 visit

using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

#define SZ 500001

bool vis[SZ][2];
unsigned int found[SZ], ans = -1;

int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	int d_end = 1;
	for (; K < SZ; K += d_end++)
		found[K] = d_end;

	deque<pair<int, int>> q;
	vis[N][1] = true, q.push_back({ N, 1 });
	while (!q.empty()) {
		auto [u, d] = q.front(); q.pop_front();

		if (d >= d_end)
			break;
		if (d <= found[u] && !((found[u] - d) % 2))
			ans = min(ans, found[u] - 1);
		
		int v;
		d++;
		if ((v = 2 * u) < SZ && !vis[v][d % 2])
			vis[v][d % 2] = true, q.push_back({ v, d });
		if ((v = u + 1) < SZ && !vis[v][d % 2])
			vis[v][d % 2] = true, q.push_back({ v, d });
		if ((v = u - 1) >= 0 && !vis[v][d % 2])
			vis[v][d % 2] = true, q.push_back({ v, d });
	}
	printf("%d", ans);
}