// 요상하게 이게 더 빠르다. 가짓수가 적고, swap이 적어서 그런 듯?

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
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
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