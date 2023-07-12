// 성공은 했지만 더 복잡하고 더 느림. (24 ms > 4 ms)

using namespace std;
#include <bits/stdc++.h>

int C;
void dfs(map<long, int> &S, vector<int>& A, int n_i, long c)
{
	if (c > C) {
		return;
	}
	S[c]++;
	for (int i = n_i; i < A.size(); i++) {
		dfs(S, A, i + 1, c + A[i]);
	}
}

int main()
{
	int N;
	scanf("%d %d", &N, &C);

	vector<int> A1, A2;
	int x;
	for (int i = 0; i < N / 2; i++) {
		scanf("%d", &x);
		A1.push_back(x);
	}
	for (int i = 0; i < N - N / 2; i++) {
		scanf("%d", &x);
		A2.push_back(x);
	}

	map<long, int> S1, S2;
	dfs(S1, A1, 0, 0), dfs(S2, A2, 0, 0);

	// prefix sum
	for (auto it2 = next(begin(S2)); it2 != end(S2); it2++) {
		it2->second += prev(it2)->second;
	}

	// two pointers
	int ans = 0;
	auto it1 = S1.begin(); auto it2 = S2.rbegin();
	while (it1 != end(S1) && it2 != rend(S2)) {
		long sum = it1->first + it2->first;
		if (sum <= C) {
			ans += it1->second * it2->second;
			it1++;
		}
		else {
			it2++;
		}
	}
	printf("%d", ans);
}