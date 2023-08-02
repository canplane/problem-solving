// BOJ 2618 P4 경찰차

using namespace std;
#include <bits/stdc++.h>

int W, N;
pair<int, int> A[1001];

uint dp[1001][1001];
pair<int, int> pre[1001][1001];

int dl(int who, int a, int b)
{
	auto [ay, ax] = A[a]; auto [by, bx] = A[b];
	if (a == 0)
		return abs(by - (who == 1 ? 1 : N)) + abs(bx - (who == 1 ? 1 : N));
	else
		return abs(by - ay) + abs(bx - ax);
}

int main()
{
	scanf("%d %d", &N, &W);
	for (int i = 1; i <= W; i++) {
		int y, x;
		scanf("%d %d", &y, &x);
		A[i] = { y, x };
	}

	memset(dp, -1, sizeof(dp));
	dp[1][0] = dl(1, 0, 1), pre[1][0] = { 0, 0 };
	dp[0][1] = dl(2, 0, 1), pre[0][1] = { 0, 0 };
	for (int i = 2; i <= W; i++) {
		for (int j = i - 2; j >= 0; j--) {
			int t;
			if ((t = dl(1, j, i) + dp[j][i - 1]) < dp[i][i - 1])
				dp[i][i - 1] = t, pre[i][i - 1] = { j, i - 1 };
			if ((t = dl(1, i - 1, i) + dp[i - 1][j]) < dp[i][j])
				dp[i][j] = t, pre[i][j] = { i - 1, j };
			if ((t = dl(2, j, i) + dp[i - 1][j]) < dp[i - 1][i])
				dp[i - 1][i] = t, pre[i - 1][i] = { i - 1, j };
			if ((t = dl(2, i - 1, i) + dp[j][i - 1]) < dp[j][i])
				dp[j][i] = t, pre[j][i] = { j, i - 1 };
		}
	}

	/*for (int i = 0; i <= W; i++) {
		for (int j = 0; j <= W; j++) {
			printf("%2d ", dp[i][j]);
		}
		printf("\n");
	}*/

	uint ans = -1;
	pair<int, int> start;
	for (int j = W - 1; j >= 0; j--) {
		if (dp[W][j] < ans)
			ans = dp[W][j], start = { W, j };
		if (dp[j][W] < ans)
			ans = dp[j][W], start = { j, W };
	}
	printf("%d\n", ans);

	deque<int> st;
	auto [i, j] = start;
	while (i > 0 || j > 0) {
		auto [ni, nj] = pre[i][j];
		st.push_back(nj == j ? 1 : 2);
		i = ni, j = nj;
	}
	while (!st.empty())
		printf("%d\n", st.back()), st.pop_back();
}