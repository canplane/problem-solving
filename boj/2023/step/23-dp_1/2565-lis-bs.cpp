// LIS: longest increasing subsequence (BS ver.)

using namespace std;
#include <cstdio>
#include <algorithm>
#include <vector>

int N;
int A[501];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		A[x] = y;
	}

	vector<int> lis;
	for (int i = 1; i <= 500; i++) {
		if (!A[i])	continue;
		auto it = lower_bound(lis.begin(), lis.end(), A[i]);
		if (it == lis.end()) {
			lis.push_back(A[i]);
		}
		else {
			*it = A[i];
		}
	}
	printf("%ld", N - lis.size());
}