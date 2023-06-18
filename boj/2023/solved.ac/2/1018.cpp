using namespace std;
#include <cstdio>
#include <algorithm>

int N, M;
char A[51][51];
int B[51][51];

int f(int y, int x)
{
	int ret = B[y][x] - B[y - 8][x] - B[y][x - 8] + B[y - 8][x - 8];
	ret = min(ret, 64 - ret);
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf(" %c", &A[y][x]);
		}
	}

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			B[y][x] = B[y][x - 1] + B[y - 1][x] - B[y - 1][x - 1];
			B[y][x] += (A[y][x] == "BW"[(x + y) % 2]);
		}
	}

	int ans = 64;
	for (int y = 8; y <= N; y++) {
		for (int x = 8; x <= M; x++) {
			ans = min(ans, f(y, x));
		}
	}
	printf("%d", ans);
}