using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int A[27][27];

int dy[] = { -1, 0, 0, 1 };
int dx[] = { 0, -1, 1, 0 };
int dfs(int y, int x)
{
	int ret = 1;
	A[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (A[ny][nx])
			ret += dfs(ny, nx);
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%1d", &A[y][x]);
		}
	}
	vector<int> v;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (A[y][x])
				v.push_back(dfs(y, x));
		}
	}
	sort(v.begin(), v.end());
	printf("%ld\n", v.size());
	for (int e : v)
		printf("%d\n", e);
}