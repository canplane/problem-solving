/*
	오래 걸린 요인: visit 초기화 안해서 오답, eratos 잘못 짬
*/

using namespace std;
#include <cstdio>
#include <vector>
#include <deque>
#include <utility>
#include <cstring>

#define NP_SZ 10000
bool np[NP_SZ];
void eratos()
{
	np[0] = np[1] = true;
	for (int i = 2; i < NP_SZ / 2; i++) {
		if (np[i])
			continue;
		for (int j = 2 * i; j < NP_SZ; j += i)
			np[j] = true;
	}
}

vector<int> adj[NP_SZ];
void _f(int i, int w)
{
	int _i = i - ((i / w) % 10) * w;
	for (int d = (w == 1000); d < 10; d++) {
		int j = _i + d * w;
		if (!np[j])
			adj[i].push_back(j);
	}
}
void graph_init()
{
	for (int i = 1000; i < NP_SZ; i++) {
		_f(i, 1), _f(i, 10), _f(i, 100), _f(i, 1000);
	}
}

bool visit[NP_SZ];
int bfs(int v, int u)
{
	memset(visit, 0, sizeof(visit));

	deque<pair<int, int>> q;
	visit[v] = true, q.push_back({ v, 0 });
	while (!q.empty()) {
		auto [v, d] = q.front(); q.pop_front();
		if (v == u)
			return d;
		for (int w : adj[v]) {
			if (!visit[w]) {
				visit[w] = true, q.push_back({ w, d + 1 });
			}
		}
	}
	return -1;
}

int main()
{
	eratos();
	graph_init();

	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y;
		scanf("%d %d", &x, &y);
		int ans = bfs(x, y);
		if (ans != -1)
			printf("%d\n", ans);
		else
			printf("Impossible\n");
	}
}