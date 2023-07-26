// [37 mins] 구현의 왕!!!
// 발상 자체는 어렵지 않으나 여러 가지 개념이 섞여 있으며, 그에 따른 구현 과정의 호흡이 꽤 길기에 실수 발생이 쉬움. (대략 2000바이트 정도) 중간중간마다 제대로 짰는지 확인해 가며 짜는 것이 중요해 보임.

using namespace std;
#include <bits/stdc++.h>

#define INF 0x7fffffff

int dj[7];
void dj_init(int n)
{
	do dj[n] = n;
	while (--n);
}
int dj_find(int u)
{
	while (dj[u] != u)	u = dj[u];
	return u;
}
bool dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	dj[rv] = ru;
	return ru != rv;
}

int N, M;
int A[12][12], D[7][7];

int dy[] = { -1, 0, 0, 1 }, dx[] = { 0, -1, 1, 0 };
void dfs(int y, int x, int c)
{
	int i, ny, nx;
	A[y][x] = c;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i], nx = x + dx[i];
		if (A[ny][nx] < 0)
			dfs(ny, nx, c);
	}
}

int main()
{
	int y, x, i, j;
	scanf("%d %d", &N, &M);
	for (y = 1; y <= N; y++)
		for (x = 1; x <= M; x++)
			scanf("%d", &A[y][x]), A[y][x] *= -1;

	// color
	int C = 0;
	for (y = 1; y <= N; y++)
		for (x = 1; x <= M; x++)
			if (A[y][x] < 0)
				dfs(y, x, ++C);

	// edge
	for (i = 1; i <= C; i++)
		for (j = 1; j <= C; j++)
			D[i][j] = INF;
	int l, c_l, r, c_r;
#define F($y, $N, $x, $M, $A)\
	for ($y = 1; $y <= $N; $y++) {\
		c_l = 0;\
		for ($x = 2; $x <= $M; $x++) {\
			if ($A && !A[y][x])\
				l = $x, c_l = $A;\
			else if ((!$A && A[y][x]) && c_l) {\
				r = $x, c_r = A[y][x];\
				if (r - l >= 2)\
					D[c_l][c_r] = D[c_r][c_l] = min(D[c_l][c_r], r - l);\
			}\
		}\
	}
	F(y, N, x, M, A[y][x - 1])
	F(x, M, y, N, A[y - 1][x])

	/* // debug
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			printf("%d ", A[y][x]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 1; i <= C; i++) {
		for (int j = 1; j <= C; j++) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
	*/

	// mst
	priority_queue<tuple<int, int, int>> pq;
	for (i = 1; i <= C; i++)
		for (j = 1; j <= C; j++)
			if (D[i][j] < INF)
				pq.push({ -D[i][j], i, j });
	int cnt = 0, ans = 0;
	dj_init(C);
	while (!pq.empty()) {
		auto [cost, i, j] = pq.top(); pq.pop();
		if (dj_union(i, j))
			cnt++, ans += -cost;
	}
	printf("%d", cnt == C - 1 ? ans : -1);
}