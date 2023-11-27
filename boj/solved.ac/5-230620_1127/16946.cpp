// BOJ 16946 G2 벽 부수고 이동하기 4

using namespace std;
#include <bits/stdc++.h>

int N, M;
int A[1002][1002], B[1002][1002];
vector<int> C = { 0, };

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x, int c)
{
	int cnt = 1;
	A[y][x] = c;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (!A[ny][nx]) {
			cnt += dfs(ny, nx, c);
		}
	}
	return cnt;
}

int main()
{
	scanf("%d %d", &N, &M);

	memset(A, -1, sizeof(A));
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &A[y][x]);
			A[y][x] *= -1;
		}
	}
	
	int c = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (!A[y][x]) {
				C.push_back(dfs(y, x, ++c));
			}
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			if (A[y][x] == -1) {
				int cnt = 1;
				set<int> m;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[i], nx = x + dx[i];
					int c = A[ny][nx];
					if (c > 0 && m.insert(c).second) {
						cnt += C[c];
					}
				}
				B[y][x] = cnt % 10;
			}
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			printf("%d", B[y][x]);
		}
		printf("\n");
	}
}