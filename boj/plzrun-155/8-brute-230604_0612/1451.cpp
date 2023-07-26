#include <cstdio>
#include <algorithm>

int A[51][51], N, M;

long f(int Ay, int Ax, int By, int Bx, int div)
{
	if (div == 1)
		return A[By][Bx] - A[By][Ax] - A[Ay][Bx] + A[Ay][Ax];

	long ret = 0;
	for (int d = 1; d < div; d++) {
		for (int y = Ay + 1; y < By; y++)
			ret = std::max(ret, f(Ay, Ax, y, Bx, d) * f(y, Ax, By, Bx, div - d));
		for (int x = Ax + 1; x < Bx; x++)
			ret = std::max(ret, f(Ay, Ax, By, x, d) * f(Ay, x, By, Bx, div - d));
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf("%1d", &A[y][x]);
			A[y][x] += A[y][x - 1] + A[y - 1][x] - A[y - 1][x - 1];
		}
	}
	printf("%ld", f(0, 0, N, M, 3));
}