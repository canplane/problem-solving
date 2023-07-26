// 숨바꼭질 4
// 틀린 이유: visit 없이 pre로만 하려다가 pre[u] = 0인 u가 존재하는데 !pre[u]로 검사해서.
// -> 그냥 visit을 웬만하면 둡시다. 축약 너무 하려 하지 말고

using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

int pre[200001];
bool visit[200001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	int ans;

	deque<pair<int, int>> q;
	visit[N] = true, q.push_back({ N, 0 });
	while (!q.empty()) {
		auto [u, d] = q.front(); q.pop_front();

		if (u == K) {
			ans = d;
			break;
		}
		
		int v;
		if ((v = 2 * u) <= 200000 && !visit[v]) {
			visit[v] = true, q.push_back({ v, d + 1 });
			pre[v] = u;
		}
		if ((v = u + 1) <= 200000 && !visit[v]) {
			visit[v] = true, q.push_back({ v, d + 1 });
			pre[v] = u;
		}
		if ((v = u - 1) >= 0 && !visit[v]) {
			visit[v] = true, q.push_back({ v, d + 1 });
			pre[v] = u;
		}
	}

	printf("%d\n", ans);

	deque<int> s;
	while (K != N) {
		s.push_front(K);
		K = pre[K];
	}
	s.push_front(N);
	for (int u : s) {
		printf("%d ", u);
	}
}