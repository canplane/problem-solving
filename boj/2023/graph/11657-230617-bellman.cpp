/*
	틀린 이유 : 자료형 크기
		음수 사이클 값이 계속 갱신되면서 underflow (-10000 * 6000 * 500 = -3 * 10^10)
*/

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>

int N, M;
vector<pair<int, int>> adj[501];

#define INF 0x7fffffff
long dist[501];
bool bellman(int v)
{
	for (int w = 1; w <= N; w++)
		dist[w] = INF;
	dist[v] = 0;

	for (int k = 0; k < N - 1; k++) {
		for (int v = 1; v <= N; v++) {
			for (auto [w, c] : adj[v]) {
				if (dist[v] != INF && dist[v] + c < dist[w]) {
					dist[w] = dist[v] + c;
				}
			}
		}
	}
	// negative cycle detection
	for (int v = 1; v <= N; v++) {
		for (auto [w, c] : adj[v]) {
			if (dist[v] != INF && dist[v] + c < dist[w]) {
				return false;
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d %d", &N, &M);
	while (M--) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		adj[A].push_back({ B, C });
	}

	if (!bellman(1)) {
		printf("-1");
	}
	else {
		for (int v = 2; v <= N; v++) {
			printf("%d\n", dist[v] != INF ? dist[v] : -1);
		}
	}
}