// prev_permutation

using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[10000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int dsc = -1;
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] > A[i + 1]) {
			dsc = i;
			break;
		}
	}
	
	if (dsc == -1) {
		printf("-1");
	}
	else {
		sort(A + dsc + 1, A + N, greater<>());
		for (int i = dsc + 1; i < N; i++) {
			if (A[i] < A[dsc]) {
				swap(A[dsc], A[i]);
				break;
			}
		}
		sort(A + dsc + 1, A + N, greater<>());

		for (int i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
	}
}