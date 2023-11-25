// BOJ 9328 G1 열쇠
// 그래프 탐색, 구현
// 탐색하면서 키에 대해서는 확보하고, 문에 대해서는 나아가지 않고 기록한다. 탐색 종료 시 마주쳤던 문들에 대해서 내가 확보한 키로 열 수 있는지 확인한다. 열 수 있는 각 문들은 그곳부터 탐색한다. 열 수 있는 문이 하나도 없다면 종료한다. 탐색은 DFS, 문을 기록하는 것은 queue를 쓰는 것이 깔끔해 보인다.

using namespace std;
#include <bits/stdc++.h>

#define INIT(o)	memset((o), 0, sizeof(o))
char buf[1000];

int h, w;
char A[102][102];
bool vis[102][102], key[26];

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x, auto &q)
{
	vis[y][x] = true;

	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!(0 <= ny && ny <= h + 1 && 0 <= nx && nx <= w + 1) || vis[ny][nx])
			continue;

		char c = A[ny][nx];
		if (c == '*')
			continue;
		if (isupper(c)) {
			vis[ny][nx] = true, q.push({ ny, nx });
			continue;
		}

		if (c == '$')
			cnt += 1;
		else if (islower(c))
			key[c - 'a'] = true;
		cnt += dfs(ny, nx, q);
	}
	return cnt;
}
void sol()
{
	INIT(A), INIT(vis), INIT(key);

	scanf("%d %d", &h, &w);
	for (int y = 1; y <= h; y++) {
		for (int x = 1; x <= w; x++) {
			scanf(" %c", &A[y][x]);
			if (A[y][x] == '.')
				A[y][x] = false;
		}
	}

	scanf("%s", buf);
	for (int i = 0; buf[i]; i++)
		key[buf[i] - 'a'] = true;

	queue<pair<int, int>> q;
	int ans = dfs(0, 0, q);

	bool b;
	do {
		b = false;
		int iter = q.size();
		while (iter--) {
			auto [y, x] = q.front(); q.pop();
			if (key[A[y][x] - 'A'])
				ans += dfs(y, x, q), b = true;
			else
				q.push({ y, x });
		}
	} while (b);

	printf("%d\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		sol();
}