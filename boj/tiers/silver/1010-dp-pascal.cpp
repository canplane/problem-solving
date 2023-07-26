#include <cstdio>

int C[31][31];
void pascal()
{
	C[0][0] = 1;
	for (int y = 1; y <= 30; y++) {
		C[y][0] = C[y][y] = 1;
		for (int x = 1; x < y; x++) {
			C[y][x] = C[y - 1][x - 1] + C[y - 1][x];
		}
	}
}

int main()
{
	pascal();

	int T;
	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d %d", &N, &M);
		printf("%d\n", C[M][N]);
	}
}