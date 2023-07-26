#include <cstdio>

int A[500000], tmp[500000];

int K;
void merge(int p, int q, int r) {
	int i = p, j = q + 1, t = 1;
    while (i <= q && j <= r) {
        if (A[i] <= A[j])
			tmp[t++] = A[i++];
        else
			tmp[t++] = A[j++];
    }
    while (i <= q)
        tmp[t++] = A[i++];
    while (j <= r)
        tmp[t++] = A[j++];
    i = p; t = 1;
    while (i <= r) {
		if (--K == 0) {
			printf("%d", tmp[t]);
		}
        A[i++] = tmp[t++];
	}
}
void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

int main()
{
	int N;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	merge_sort(0, N - 1);
	if (K > 0) {
		printf("-1");
	}
}