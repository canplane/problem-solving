#include	<stdio.h>
#include	<stdlib.h>
#include	<time.h>

void SWAP(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int A[5000001];
int N, K;

void nth_element(int l, int nth, int r)
{
	if (l == r) return;

	int m = l + rand() % (r - l);
	SWAP(&A[l], &A[m]);
	int pivot = A[l];
	A[r] = pivot + 1;

	int i = l, j = r;
	while (1) {
		while (A[++i] <= pivot);
		while (A[--j] > pivot);
		if (i >= j)		break;
		SWAP(&A[i], &A[j]);
	}
	SWAP(&A[l], &A[j]);

	if (nth < j)
		nth_element(l, nth, j);
	else if (nth > j)
		nth_element(j + 1, nth, r);
}

int main()
{
	srand(time(NULL));

	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", A + i);
	}
	nth_element(0, K - 1, N);
	printf("%d", A[K - 1]);
}