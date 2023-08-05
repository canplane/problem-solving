#include <cstdio>

int N, A[8];

int M, comb[8];
void combi_rep(int n_i, int r_i)
{
	if (r_i == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", comb[i]);
		printf("\n");
		return;
	}
	for (int i = n_i; i < N; i++) {
		comb[r_i] = A[i], combi_rep(i, r_i + 1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		A[i] = i + 1;
	
	combi_rep(0, 0);
}