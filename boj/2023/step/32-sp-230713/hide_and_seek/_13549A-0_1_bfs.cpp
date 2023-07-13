// 숨바꼭질 3
// https://www.acmicpc.net/board/view/121219
// 0-1 BFS 기본 문제. (O(V + E) 0-1 BFS가 O((V + E)logV) 다익스트라보다 효율적이므로)
// 0-1 BFS는 매 시점 후보들의 값 차이가 at most 1로, 중간에 값을 끼워넣을 필요가 없어 덱을 쓰는 것이지, 기본적으로는 우선순위 큐 기반 다익스트라와 로직이 동일.
// 따라서 다익스트라와 동일하게 실제 방문 시 visit을 set해야 하는 것에 주의해야 함.
// 반례: 4 6 (4 -> 5 -> 6이 아니라 4 -> 3 -> 6)
// 최단 경로 알고리즘 설명: https://anz1217.tistory.com/23

using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

bool visit[200001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	deque<pair<int, int>> q;
	q.push_back({ N, 0 });
	while (!q.empty()) {
		auto [u, d] = q.front(); q.pop_front();
		if (visit[u]) {
			continue;
		}
		visit[u] = true;

		if (u == K) {
			printf("%d", d);
			break;
		}
		
		int v;
		if ((v = 2 * u) <= 200000 && !visit[v]) {
			q.push_front({ v, d });		//
		}
		if ((v = u + 1) <= 200000 && !visit[v]) {
			q.push_back({ v, d + 1 });
		}
		if ((v = u - 1) >= 0 && !visit[v]) {
			q.push_back({ v, d + 1 });
		}
	}
}