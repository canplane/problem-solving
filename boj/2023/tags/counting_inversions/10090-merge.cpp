// counting inversions : 세그먼트 트리가 머지 소트보다 더 느리다. (2배)

using namespace std;
#include <cstdio>

int N;
int A[1000000], B[1000000];

long swaps;
void merge(int dst[], int src[], int l, int r)
{
	if (l + 1 == r) {
		return;
	}
	
	int m = l + (r - l) / 2;
	merge(src, dst, l, m), merge(src, dst, m, r);

	int i = l, j = m, k = l;
	while (i < m && j < r) {
		if (src[i] <= src[j]) {
			dst[k++] = src[i++];
		}
		else {
			swaps += j - k;
			dst[k++] = src[j++];
		}
	}
	while (i < m) {
		dst[k++] = src[i++];
	}
	while (j < r) {
		dst[k++] = src[j++];
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		B[i] = A[i];
	}
	merge(A, B, 0, N);
	printf("%ld", swaps);
}