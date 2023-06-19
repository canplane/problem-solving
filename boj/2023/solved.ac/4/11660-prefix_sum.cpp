// 누적 합

#include <cstdio>

int N, M;
int A[1025][1025], B[1025][1025];

int main()
{
	scanf("%d %d", &N, &M);
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			scanf("%d", &A[y][x]);
			B[y][x] = A[y][x] + (B[y - 1][x] + B[y][x - 1] - B[y - 1][x - 1]);
		}
	}

	int y1, x1, y2, x2;
	while (M--) {
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		printf("%d\n", B[y2][x2] - B[y1 - 1][x2] - B[y2][x1 - 1] + B[y1 - 1][x1 - 1]);
	}
}