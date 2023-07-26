// 그냥 BFS 기본 문제(3차원 필요 없음). 벽 도달하면 거리 계산하되 enqueue는 하지 않음. 두 점 (1, 1), (N, M)에 대하여 거리 행렬 각각 만들어 주고, 합한 것 중 최솟값 계산.

using namespace std;
#include <cstdio>
#include <deque>
#include <utility>
#include <cstring>

int N, M;
int A[1000][1000], D1[1000][1000], D2[1000][1000];

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
void bfs(int D[][1000], int y, int x)
{
	deque<pair<int, int>> q;
	D[y][x] = 1, q.push_back({ y, x });
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if ((0 <= ny && ny < N && 0 <= nx && nx < M) && !D[ny][nx]) {
				D[ny][nx] = D[y][x] + 1;
				if (!A[ny][nx]) {
					q.push_back({ ny, nx });
				}
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%1d", &A[y][x]);
		}
	}
	bfs(D1, 0, 0), bfs(D2, N - 1, M - 1);

	int ans = -1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (D1[y][x] && D2[y][x] && D1[y][x] + D2[y][x] - 1 < (unsigned int)ans) {
				ans = D1[y][x] + D2[y][x] - 1;
			}
		}
	}
	printf("%d", ans);
}