// 사이클 개수 세기
// 유방향이든 무방향이든 그래프의 사이클 개수를 구하는 것은 NP-hard. (TSP 생각)
// 그러나 해당 문제와 같이 out-degree가 1로 고정된다면 back edge의 수가 사이클 개수가 됨.

using namespace std;
#include <bits/stdc++.h>

int N, M;
char A[1000][1000];
unordered_map<char, pair<int, int>> dir = {
	{ 'U', { -1, 0 } }, { 'L', { 0, -1 } }, { 'R', { 0, 1 } }, { 'D', { 1, 0 }},
};

int cnt;
bool vis[1000][1000], finish[1000][1000];
void dfs(int y, int x)
{
	vis[y][x] = true;

	auto [dy, dx] = dir[A[y][x]];
	int ny = y + dy, nx = x + dx;
	if (!vis[ny][nx]) {
		dfs(ny, nx);
	}
	else if (!finish[ny][nx]) {
		cnt++;
	}

	finish[y][x] = true;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf(" %c", &A[y][x]);
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!vis[y][x]) {
				dfs(y, x);
			}
		}
	}

	printf("%d", cnt);
}