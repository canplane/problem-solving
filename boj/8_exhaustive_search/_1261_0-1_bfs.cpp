/* 가중치가 0 또는 1인 그래프에서 최단 경로를 찾는 효율적인 코드 작성하는 문제. 
 *
 * 다익스트라는 이진 힙을 사용하면 O(ElogV), 피보나치 힙을 사용하면 O(E + VlogV)
 * -> naive solution!
 * 이것 말고, bfs를 이용한, 매우 간단하며 더 효율적인 아름다운 기법이 있다.
 * optimize solution: 0-1 BFS: 간선의 가중치가 0 또는 1인 그래프에서 작동
 * 다익스트라처럼 큐에는 오직 이전 정점을 통해 최단 거리가 줄어든 정점만 큐에 삽입
 * 그러면서 동시에 큐는 항상 시작점로부터의 거리에 대해 정렬된 상태.
 * 
 * u 정점에서 v 정점으로 갈 때 v는 u와 같은 레벨(가중치 0)이거나, 1 레벨 아래(가중치 1)이다.
 * v 정점이 u에 의해 최단 거리가 단축되었고, u와 같은 레벨이라면 큐의 앞 부분에 v 삽입.
 * 반대라면 뒷 부분에 삽입.
 * -> 정렬된 상태 유지!
 * -> deque!
 * 
 * 이전 정점을 통해 최단 거리가 줄어든 정점만 큐에 삽입하되, u -> v의 가중치가 0이면 push_front, 1이면 push_back.
 * 
 * 0-1 bfs < dijkstra < bfs 순으로 빠를 듯.
 */

#include <cstdio>
#include <deque>
#include <utility>
#define INF 0x7fffffff
using namespace std;

int map[100][100], dist[100][100], N, M;
int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

int bfs_01() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dist[i][j] = INF;

	deque<pair<int, int>> deq;
	deq.push_front({ 0, 0 }), dist[0][0] = 0;

	while (!deq.empty()) {
		auto [y, x] = deq.front();
		deq.pop_front();
		if (y == N - 1 && x == M - 1)
			break;
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue;
			if (dist[y][x] + map[ny][nx] < dist[ny][nx]) {
				dist[ny][nx] = dist[y][x] + map[ny][nx];
				if (map[ny][nx])
					deq.push_back({ ny, nx });
				else
					deq.push_front({ ny, nx });
			}
		}
	}
	return dist[N - 1][M - 1];
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	printf("%d", bfs_01());
}