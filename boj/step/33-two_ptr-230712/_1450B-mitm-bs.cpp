// 2n개 데이터에 대하여 naive는 O(2^(2n)), MITM + BS는 O(n * 2^n).

using namespace std;
#include <bits/stdc++.h>

int A[30], C;
void dfs(vector<int>& S, int l, int r, long c)
{
	if (c > C)	return;
	S.push_back(c);
	for (int i = l; i < r; i++)
		dfs(S, i + 1, r, c + A[i]);
}

int main()
{
	int N;
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	vector<int> S1, S2;
	dfs(S1, 0, N / 2, 0), dfs(S2, N / 2, N, 0);
	sort(begin(S1), end(S1)), sort(begin(S2), end(S2));

	int ans = 0;
	for (int s1 : S1)
		ans += upper_bound(begin(S2), end(S2), C - s1) - begin(S2);
	printf("%d", ans);
}