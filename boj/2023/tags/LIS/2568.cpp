using namespace std;
#include <bits/stdc++.h>

#define SZ 500001

int N;
int A[SZ];

vector<int> lis;
int dp[SZ];

int main()
{
	scanf("%d", &N);
	for (int k = 0; k < N; k++) {
		int i, j;
		scanf("%d %d", &i, &j);
		A[i] = j;
	}

	for (int i = 1; i < SZ; i++) {
		if (!A[i]) {
			continue;
		}
		int j = upper_bound(lis.begin(), lis.end(), A[i]) - lis.begin();
		if (j == lis.size()) {
			lis.push_back(A[i]);
		}
		else {
			lis[j] = A[i];
		}
		dp[i] = j + 1;
	}

	int j = lis.size();
	vector<int> nseq;
	for (int i = SZ - 1; i >= 1; i--) {	// 뒤부터!
		if (!dp[i]) {
			continue;
		}
		if (j == dp[i]) {
			j--;
		}
		else {
			nseq.push_back(i);
		}
	}

	printf("%ld\n", N - lis.size());
	for (auto it = nseq.rbegin(); it != nseq.rend(); it++) {
		printf("%d\n", *it);
	}
}

/*
8
2
2 9
1 9
1 4
1 4 6
1 4 6 7
1 4 6 7 10
*/