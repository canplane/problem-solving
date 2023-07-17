using namespace std;
#include <cstdio>

#define ALL(n) ((1 << (n)) - 1)

int N, K;
int btn[30];
bool twist[30][30];

int dp_hi[1 << 15], dp_lo[1 << 15];

int dfs(int dp[], int hi, int lo, int S)
{
	if (dp[S]) {
		return dp[S];
	}
	if (S == 0) {
		return dp[S] = 1;
	}

	int n = 0;
	for (int i = hi - 1; i >= lo; i--) {
		if (S & (1 << i)) {
			n = i;
			break;
		}
	}

	int _S = S;
	_S &= ~(1 << n);
	int cnt = dfs(dp, hi, lo, _S);
	
	for (int i = hi - 1; i >= lo; i--) {
		if (twist[i][n]) {
			_S &= ~(1 << i);
		}
	}
	cnt += dfs(dp, hi, lo, _S);

	dp[S] = cnt;
	return dp[S] = cnt;
}

int main()
{
	scanf("%d", &N);
	for (int i = N - 1; i >= 0; i--) {
		scanf("%d", &btn[i]);
		for (int j = N - 1; j > i; j--) {
			if (btn[j] > btn[i]) {
				twist[i][j] = twist[j][i] = true;
			}
		}
	}
	scanf("%d", &K);


	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", twist[i][j]);
		}
		printf("\n");
	}*/

	int cnt = dfs(dp_lo, 15, 0, ALL(N));
	/*if (cnt < K) {
		printf("-1");
	}*/
	printf("%d", cnt);
}