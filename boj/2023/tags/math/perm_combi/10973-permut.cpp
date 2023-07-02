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

	if (prev_permutation(A, A + N)) {
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);
	}
	else {
		printf("-1");
	}
}