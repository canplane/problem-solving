using namespace std;
#include <cstdio>
#include <algorithm>

int N, A[8];

int M, comb[8];
bool visit[8];
void combi_rep(int n_i, int r_i)
{
	if (r_i == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", comb[i]);
		printf("\n");
		return;
	}

	int prev = -1;	//
	for (int i = n_i; i < N; i++) {
		if (prev != A[i]) {
			prev = A[i];
			comb[r_i] = A[i], combi_rep(i, r_i + 1);
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);

	combi_rep(0, 0);
}