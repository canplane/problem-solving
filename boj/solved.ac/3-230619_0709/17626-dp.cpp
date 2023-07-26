// [5 mins]

using namespace std;
#include <cstdio>
#include <algorithm>

int dp[50001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		dp[i] = dp[i - 1] + 1;
		for (int j = 2; i - j * j >= 0; j++) {
			dp[i] = min(dp[i], 1 + dp[i - j * j]);
		}
	}
	printf("%d", dp[N]);
}