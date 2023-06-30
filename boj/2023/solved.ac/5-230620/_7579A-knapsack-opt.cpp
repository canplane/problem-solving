// inverse

using namespace std;
#include <cstdio>
#include <algorithm>

int N, M;
int m[101], c[101];
int dp[10001];	// space optimization

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", &m[i]);
	for (int j = 1; j <= N; j++)
		scanf("%d", &c[j]);

	for (int i = 1; i <= N; i++) {
		for (int j = 10000; j >= 1; j--) {
			if (j >= c[i])
				dp[j] = max(dp[j], dp[j - c[i]] + m[i]);
		}
	}
	for (int j = 1; j <= 10000; j++) {
		if (dp[j] >= M) {
			printf("%d", j);
			break;
		}
	}
}