using namespace std;
#include <bits/stdc++.h>

int N, M;
int A[8][8];

bool vis[8][8];
int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int bfs()
{
	memset(vis, 0, sizeof(vis));

	deque<pair<int, int>> q;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (A[y][x] == 2) {
				vis[y][x] = true, q.push_back({ y, x });
			}
		}
	}
	while (!q.empty()) {
		auto [y, x] = q.front(); q.pop_front();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i], nx = x + dx[i];
			if ((0 <= ny && ny < N && 0 <= nx && nx < M) && !A[ny][nx] && !vis[ny][nx]) {
				vis[ny][nx] = true;
				q.push_back({ ny, nx });
			}
		}
	}
	int cnt = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!A[y][x] && !vis[y][x]) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d %d", &N, &M);

	vector<pair<int, int>> candi;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &A[y][x]);
			if (!A[y][x]) {
				candi.push_back({ y, x });
			}
		}
	}
	
	vector<bool> combi(3, true);
	combi.resize(candi.size());

	int ans = 0;
	do {
		for (int i = 0; i < combi.size(); i++) {
			if (combi[i]) {
				auto [y, x] = candi[i];
				A[y][x] = 1;
			}
		}
		ans = max(ans, bfs());
		for (int i = 0; i < combi.size(); i++) {
			if (combi[i]) {
				auto [y, x] = candi[i];
				A[y][x] = 0;
			}
		}
	} while (prev_permutation(begin(combi), end(combi)));
	printf("%d", ans);
}