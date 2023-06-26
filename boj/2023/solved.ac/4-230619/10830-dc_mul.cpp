// 분할 정복을 이용한 거듭제곱
/*
	틀린 이유: B = 1일 때 나머지 연산 안해줘서! (그래서 단위 행렬로 세팅해서 곱하는 방식 적용함)
*/

#include <cstdio>

int N;
int A[5][5], C[5][5];

void mul(int c[][5], int a[][5], int b[][5])
{
	int i, j, k;
	int t[5][5];

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			t[i][j] = 0;
			for (k = 0; k < N; k++)
				t[i][j] = (t[i][j] + a[i][k] * b[k][j]) % 1000;
		}
	}
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			c[i][j] = t[i][j];
	}
}
void dc(long n)
{
	if (n == 0)
		return;
	dc(n / 2), mul(C, C, C);
	if (n % 2)
		mul(C, C, A);
}

int main()
{
	int i, j;
	long B;

	scanf("%d %ld", &N, &B);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			scanf("%d", &A[i][j]);
		C[i][i] = 1;
	}

	dc(B);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}