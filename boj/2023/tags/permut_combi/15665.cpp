using namespace std;
#include <cstdio>
#include <algorithm>

int N, A[8];

int M, perm[8];
void permut_rep(int r_i)
{
	if (r_i == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", perm[i]);
		}
		printf("\n");
		return;
	}
	int pre = -1;
	for (int i = 0; i < N; i++) {
		if (A[i] == pre) {
			continue;
		}
		pre = A[i];
		perm[r_i] = A[i];
		permut_rep(r_i + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);

	permut_rep(0);
}