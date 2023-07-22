// [1 hours] 구현 실수가 너무 많아... 특히 분할 정복 만나면 에바야...

#include <cstdio>

int K, x0, y0;
int A[129][129], c;

void block(int x, int y, int n, int dir)
{
	if (n == 2) {
		++c;
		if (dir != 1)	A[y][x] = c;
		if (dir != 2)	A[y][x - 1] = c;
		if (dir != 3)	A[y - 1][x - 1] = c;
		if (dir != 4)	A[y - 1][x] = c;
		return;
	}

	int nn = n / 2;
	block(x, y, nn, dir);
	if (dir != 1)	block(x + nn / 2, y + nn / 2, nn, 3);
	if (dir != 2)	block(x - nn / 2, y + nn / 2, nn, 4);
	if (dir != 3)	block(x - nn / 2, y - nn / 2, nn, 1);
	if (dir != 4)	block(x + nn / 2, y - nn / 2, nn, 2);
}
void dc(int x, int y, int n)
{
	int dir, ny, nx;
	if (n == 2) {
		if (x0 >= x && y0 >= y)	dir = 1, A[y][x] = -1;
		if (x0 < x && y0 >= y)	dir = 2, A[y][x - 1] = -1;
		if (x0 < x && y0 < y)	dir = 3, A[y - 1][x - 1] = -1;
		if (x0 >= x && y0 < y)	dir = 4, A[y - 1][x] = -1;
		block(x, y, n, dir);
		return;
	}

	int nn = n / 2;
	if (x0 >= x && y0 >= y)	dir = 1, ny = y + nn / 2, nx = x + nn / 2;
	if (x0 < x && y0 >= y)	dir = 2, ny = y + nn / 2, nx = x - nn / 2;
	if (x0 < x && y0 < y)	dir = 3, ny = y - nn / 2, nx = x - nn / 2;
	if (x0 >= x && y0 < y)	dir = 4, ny = y - nn / 2, nx = x + nn / 2;
	dc(nx, ny, nn);
	block(x, y, n, dir);
}

int main()
{
	scanf("%d %d %d", &K, &x0, &y0);
	
	int N = 1 << K;
	dc(1 + N / 2, 1 + N / 2, N);
	
	for (int y = N; y >= 1; y--) {
		for (int x = 1; x <= N; x++) {
			printf("%d ", A[y][x]);
		}
		printf("\n");
	}
}