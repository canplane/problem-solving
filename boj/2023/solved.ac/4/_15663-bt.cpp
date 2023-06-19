using namespace std;
#include <cstdio>
#include <algorithm>

int N, A[8];

int M, perm[8];
bool visit[8];
void permut(int r_i)
{
	if (r_i == M) {
		for (int i = 0; i < M; i++)
			printf("%d ", perm[i]);
		printf("\n");
		return;
	}

	int prev = -1;	//
	for (int i = 0; i < N; i++) {
		if (!visit[i] && prev != A[i]) {
			prev = A[i];
			visit[i] = true;
			perm[r_i] = A[i], permut(r_i + 1);
			visit[i] = false;
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

	permut(0);
}