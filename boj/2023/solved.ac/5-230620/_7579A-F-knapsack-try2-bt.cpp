using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int N, M;
int m[101], c[101];

int dfs(int i, int _m, int _c)
{
	if (_m >= M) {
		return _c;
	}
	if (i == N + 1) {
		return INF;
	}

	int ret = INF;
	for (; i <= N; i++) {
		ret = min(ret, dfs(i + 1, _m, _c));
		ret = min(ret, dfs(i + 1, _m + m[i], _c + c[i]));
	}
	return ret;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &m[i]);
	for (int j = 1; j <= N; j++)
		scanf("%d", &c[j]);
	
	printf("%d", dfs(1, 0, 0));
}