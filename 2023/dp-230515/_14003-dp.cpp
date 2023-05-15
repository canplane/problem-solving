#include <cstdio>
#include <algorithm>
using namespace std;

int A[1'000'000], N;

int LIS[1'000'000], len_LIS;
int dp[1'000'000];

int ans, seq[1'000'000];

int main()
{
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		
		int l = lower_bound(LIS, LIS + len_LIS, A[i]) - LIS;
		if (l == len_LIS) {
			len_LIS += 1; LIS[l] = A[i];
			dp[i] = l;
		}
		else if (A[i] != LIS[l]) {
			LIS[l] = A[i];
			dp[i] = l;
		}
	}
	ans = len_LIS;
	for (i = 0; i < N; i++)
		if (dp[i] == ans - 1)	break;
	seq[dp[i]] = A[i];
	for (int j = i - 1; j >= 0; j--) {
		if (dp[j] + 1 == dp[i] && A[j] < A[i]) {
			seq[dp[j]] = A[j];
			if (dp[j] == 0)	break;
			i = j;
		}
	}
	printf("%d\n", ans);
	for (i = 0; i < ans; i++)
		printf("%d ", seq[i]);
	puts("");
}