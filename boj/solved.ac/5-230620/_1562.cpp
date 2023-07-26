// { 9876543210 } if N = 10

using namespace std;
#include <cstdio>

#define L dp[k + 1][d - 1][b | (1 << (d - 1))]
#define R dp[k + 1][d + 1][b | (1 << (d + 1))]
#define B 1'000'000'000

int N;
long dp[101][10][1 << 10];

int main()
{
	int N;
	scanf("%d", &N);
	
	for (int d = 1; d < 10; d++) {
		dp[1][d][1 << d] = 1;
	}
	for (int k = 1; k < N; k++) {
		for (int d = 0; d < 10; d++) {
			for (int b = 0; b < (1 << 10); b++) {
				if (d > 0) {
					L = (L + dp[k][d][b]) % B;
				}
				if (d < 9) {
					R = (R + dp[k][d][b]) % B;
				}
			}
		}
	}
	
	long ans = 0;
	for (int d = 0; d < 10; d++) {
		ans = (ans + dp[N][d][(1 << 10) - 1]) % B;
	}
	printf("%ld", ans);
}