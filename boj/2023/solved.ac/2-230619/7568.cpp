#include <cstdio>

int N;
int A[50][2];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[i][0], &A[i][1]);
	}
	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;
			if (A[i][0] < A[j][0] && A[i][1] < A[j][1])
				rank++;
		}
		printf("%d ", rank);
	}
}