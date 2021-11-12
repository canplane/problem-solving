// 우선 순위 큐는 이용하지만, dist 배열을 사용하지 않고 단순히 인자로 거리 값 넘기고 있으므로 visited(found) 필요.
// 여기서는 우선 순위 큐가 알아서 정렬해주기 때문에 next v를 큐에 넣을 때 found 처리해도 됨.

#include <cstdio>
#include <queue>
using namespace std;

int map[100][100], N, M;
bool found[100][100];

int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

struct Node {
	int dist, y, x;
	bool operator<(const Node& node) const {
		return dist > node.dist;
	}
};

int dijkstra() {
	int ret;
	priority_queue<Node> pq;
	pq.push({ 0, 0, 0 }), found[0][0] = true;
	while (!pq.empty()) {
		Node node = pq.top();
		pq.pop();
		if (node.y == N - 1 && node.x == M - 1) {
			ret = node.dist;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = node.y + dy[i], nx = node.x + dx[i];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || found[ny][nx])
				continue;
			pq.push({ node.dist + map[ny][nx], ny, nx }), found[ny][nx] = true;
			// bfs는 넣을 때 방문 처리 안 하면 메모리 초과, 시간 초과!
		}
	}
	return ret; 
}

int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%1d", &map[i][j]);
	printf("%d", dijkstra());
}