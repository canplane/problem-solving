// BOJ 2629 G3 양팔저울

using namespace std;
#include <bits/stdc++.h>

int N;
int A[31];
bool dp[31][15001];

bool check(int i, int j)
{
	if (0 <= j && j <= 15000) {
		return dp[i][j];
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}

	dp[0][0] = true;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 15000; j++) {
			// j, (j - A[i]) + A[i], (j + A[i]) - A[i], A[i] - (A[i] - j)
			if (check(i - 1, j) || check(i - 1, j - A[i]) || check(i - 1, j + A[i]) || check(i - 1, A[i] - j)) {	
				dp[i][j] = true;
			}
		}
	}

	int M;
	scanf("%d", &M);
	while (M--) {
		int j;
		scanf("%d", &j);
		printf("%s ", check(N, j) ? "Y" : "N");
	}
}