/* [0-1 knapsack (배낭 문제)]
idea: i번째까지의 물건 중 최대 가치는 i번째를 포함하거나 포함하지 않은 최대 가치 중 큰 것.
DP: 저울 문제(i번째 추를 이용하여 무게 k를 맞출 수 있는가)와 비슷
-> O(NK) (물건 N개, 최대 무게 K)
K < 2^N, 그리고 물건 무게, 가치들이 정수여야 효과가 있다.
(brute인 O(2^N)보다 작아야 하므로)
*/

using namespace std;
#include <cstdio>
#include <algorithm>

int N, K;
int W[101], V[101];
int dp[100001];	// space optimization

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = K; j >= 1; j--) {
			if (j >= W[i]) {
				dp[j] = max(dp[j], dp[j - W[i]] + V[i]);
			}
		}
	}
	printf("%d", dp[K]);
}