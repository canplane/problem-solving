using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[8];

int perm[8];
bool visit[8];
void dfs(int r)
{
	if (r == N) {
		for (int i = 0; i < N; i++)
			printf("%d ", perm[i]);
		printf("\n");
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			perm[r] = A[i], dfs(r + 1);
			visit[i] = false;
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		A[i] = i + 1;

	dfs(0);
}