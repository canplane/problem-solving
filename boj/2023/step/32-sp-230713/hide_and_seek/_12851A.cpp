// 숨바꼭질 2
// 도달 개수 세는 건 visit을 실제 방문 시에 set하는 걸로 해결 가능.

using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

bool visit[200001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	int ans, cnt = 0;
	deque<pair<int, int>> q;
	q.push_back({ N, 0 });
	while (!q.empty()) {
		auto [u, d] = q.front(); q.pop_front();	
		visit[u] = true;

		if (u == K && (!cnt || d == ans)) {		//
			ans = d, cnt++;
		}
		if (cnt) {
			continue;
		}

		int v;
		if ((v = 2 * u) <= 200000 && !visit[v]) {
			q.push_back({ v, d + 1 });
		}
		if ((v = u + 1) <= 200000 && !visit[v]) {
			q.push_back({ v, d + 1 });
		}
		if ((v = u - 1) >= 0 && !visit[v]) {
			q.push_back({ v, d + 1 });
		}
	}
	printf("%d\n%d", ans, cnt);
}