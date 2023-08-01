// BOJ 13992 G1 방법을 출력하지 않는 숫자 맞추기
// [1 hours] 틀린 이유: 설계는 잘 함. 그냥 주의 부족 (rot < 9, r = 10 - l)

using namespace std;
#include <bits/stdc++.h>

int N;
int A[10001], B[10001];

int dp[10001][10];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%1d", &A[i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%1d", &B[i]);
	}
	
	// rot은 왼쪽으로 얼마나 회전되었는가
	for (int rot = 0; rot < 10; rot++) {
		int l = (B[N] - (A[N] + rot) + 20) % 10, r = (10 - l) % 10;
		dp[N][rot] = min(l, r);
	}
	for (int i = N - 1; i >= 1; i--) {
		for (int rot = 0; rot < 10; rot++) {
			int l = (B[i] - (A[i] + rot) + 20) % 10, r = (10 - l) % 10;
			dp[i][rot] = min(l + dp[i + 1][(rot + l) % 10], r + dp[i + 1][rot]);
		}
	}
	printf("%d", dp[1][0]);
}