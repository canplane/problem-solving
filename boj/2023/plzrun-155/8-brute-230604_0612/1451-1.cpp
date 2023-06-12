using namespace std;
#include <cstdio>
#include <algorithm>

int N, M;
int A[50][50];

long f(int Ax, int Ay, int Bx, int By)
{
	long ret = 0;
	for (int y = Ay; y < By; y++)
		for (int x = Ax; x < Bx; x++)
			ret += A[y][x];
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%1d", &A[y][x]);
		}
	}

	long ans = 0;
	for (int y = 1; y < N; y++) {
		for (int y1 = y + 1; y1 < N; y1++) {
			ans = max(ans, f(0, 0, M, y) * f(0, y, M, y1) * f(0, y1, M, N));
		}
		for (int x = 1; x < M; x++) {
			ans = max(ans, (f(0, 0, x, y) * f(x, 0, M, y)) * f(0, y, M, N));
			ans = max(ans, f(0, 0, M, y) * (f(0, y, x, N) * f(x, y, M, N)));
		}
	}
	for (int x = 1; x < M; x++) {
		for (int x1 = x + 1; x1 < M; x1++) {
			ans = max(ans, f(0, 0, x, N) * f(x, 0, x1, N) * f(x1, 0, M, N));
		}
		for (int y = 1; y < N; y++) {
			ans = max(ans, (f(0, 0, x, y) * f(0, y, x, N)) * f(x, 0, M, N));
			ans = max(ans, f(0, 0, x, N) * (f(x, 0, M, y) * f(x, y, M, N)));
		}
	}
	printf("%ld", ans);
	
}