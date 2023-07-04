using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[8];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		A[i] = i + 1;

	do {
		for (int i = 0; i < N; i++)
			printf("%d ", A[i]);
		printf("\n");
	} while (next_permutation(A, A + N));
}