#include <cstdio>

int N, S;
int A[20];

int dfs(int i, int diff)
{
	int ret = (diff == 0);
	for (int j = i; j < N; j++)
		ret += dfs(j + 1, diff - A[j]);
	return ret;	
}

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	printf("%d", dfs(0, S) - (S == 0));
}