using namespace std;
#include <cstdio>
#include <algorithm>

int n;
int A[502][500], dp[502][500];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++)
			scanf("%d", &A[i][j]);
	}

	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= i; j++)
			dp[i][j] = A[i][j] + max(dp[i + 1][j], dp[i + 1][j + 1]);
	}
	printf("%d", dp[1][1]);
}