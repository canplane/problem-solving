// next_permutation

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

	int asc = -1;
	for (int i = N - 2; i >= 0; i--) {
		if (A[i] < A[i + 1]) {
			asc = i;
			break;
		}
	}

	if (asc == -1) {
		printf("-1");
	}
	else {
		sort(A + asc + 1, A + N);
		for (int i = asc; i < N; i++) {
			if (A[asc] < A[i]) {
				swap(A[asc], A[i]);
				break;
			}
		}
		sort(A + asc + 1, A + N);

		for (int i = 0; i < N; i++) {
			printf("%d ", A[i]);
		}
	}
}