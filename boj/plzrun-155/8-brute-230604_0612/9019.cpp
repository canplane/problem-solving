using namespace std;
#include <cstdio>
#include <deque>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>

#define SZ 10000
vector<pair<char, int>> adj[SZ];
void init_graph()
{
	for (int i = 0; i < SZ; i++) {
		adj[i].push_back({ 'D', (2 * i) % SZ });
		adj[i].push_back({ 'S', (i + SZ - 1) % SZ });
		adj[i].push_back({ 'L', (i * 10) % SZ + (i / (SZ / 10)) });
		adj[i].push_back({ 'R', (i % 10) * (SZ / 10) + (i / 10) });
	}
}

pair<char, int> parent[SZ];
void print(int x, int y)
{
	string s = "";
	int v = y;
	while (v != x) {
		auto [c, w] = parent[v];
		s += c;
		v = w;
	}
	reverse(s.begin(), s.end());
	printf("%s\n", s.c_str());
}


bool visit[SZ];
void bfs(int x, int y)
{
	memset(visit, 0, sizeof(visit));

	deque<int> q;
	visit[x] = true, q.push_back(x);
	while (!q.empty()) {
		int v = q.front(); q.pop_front();
		if (v == y) {
			print(x, y);
			break;
		}
		for (auto [c, w] : adj[v]) {
			if (!visit[w]) {
				parent[w] = { c, v };
				visit[w] = true, q.push_back(w);
			}
		}
	}
}

int main()
{
	init_graph();

	int T;
	scanf("%d", &T);
	while (T--) {
		int x, y;
		scanf("%d %d", &x, &y);
		bfs(x, y);
	}
}