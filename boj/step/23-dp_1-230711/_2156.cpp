// BOJ 2156 S1 포도주 시식
// 안 마시는 경우를 생각하지 않았다!

using namespace std;
#include <bits/stdc++.h>

int N;
int A[10001];
int dp[10001];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	dp[1] = A[1];
	dp[2] = A[2] + A[1];
	for (int i = 3; i <= N; i++) {
		dp[i] = max(dp[i - 1], max(A[i] + A[i - 1] + dp[i - 3], A[i] + dp[i - 2]));
	}
	printf("%d", dp[N]);
}