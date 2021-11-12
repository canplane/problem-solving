#include <cstdio>

int num[20], N, S;

int dfs(int i, int diff) {
	int ret = 0;
	if (i && !diff)
		ret++;
	for (; i < N; i++)
		ret += dfs(i + 1, diff - num[i]);
	return ret;
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &num[i]);
	printf("%d", dfs(0, S));
}