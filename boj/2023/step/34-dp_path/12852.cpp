using namespace std;
#include <cstdio>
#include <algorithm>

int dp[1000001];

int main()
{
	int X;
	scanf("%d", &X);

	for (int i = 2; i <= X; i++) {
		dp[i] = dp[i - 1] + 1;
		if (!(i % 2)) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
		}
		if (!(i % 3)) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
		}
	}
	printf("%d\n", dp[X]);
	printf("%d ", X);
	while (X > 1) {
		if (!(X % 2) && dp[X] == dp[X / 2] + 1) {
			printf("%d ", X /= 2);
		}
		else if (!(X % 3) && dp[X] == dp[X / 3] + 1) {
			printf("%d ", X /= 3);
		}
		else {
			printf("%d ", X -= 1);
		}
	}
}