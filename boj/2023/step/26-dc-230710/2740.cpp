#include <cstdio>

void input(int A[][100], int& N, int& M)
{
	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf("%d", &A[y][x]);
		}
	}
}

int A[100][100], B[100][100], N, M, K;
int main()
{
	input(A, N, M), input(B, M, K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			int c = 0;
			for (int k = 0; k < M; k++) {
				c += A[i][k] * B[k][j];
			}
			printf("%d ", c);
		}
		puts("");
	}
}