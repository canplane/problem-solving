using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>

int A[500000], buf[500000];
long ans;

void merge_sort(int dst[], int src[], int l, int r)
{
	if (l + 1 >= r)	return;

	int m = l + (r - l) / 2;
	merge_sort(src, dst, l, m), merge_sort(src, dst, m, r);
	
	int i = l, j = m, k = l;
	while (i < m && j < r) {
		if (src[i] <= src[j])
			dst[k++] = src[i++];
		else
			dst[k++] = src[j++], ans += j - k;	//
	}
	while (i < m)
		dst[k++] = src[i++];
	while (j < r)
		dst[k++] = src[j++];
}

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	memcpy(buf, A, N * sizeof(int)), merge_sort(A, buf, 0, N);
	printf("%ld", ans);
}