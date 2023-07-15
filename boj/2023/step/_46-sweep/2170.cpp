using namespace std;
#include <cstdio>
#include <utility>
#include <algorithm>

int N;
pair<int, int> A[1000000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[i].first, &A[i].second);
	}
	sort(A, A + N);

	int ans, r;
	ans = (r = A[0].second) - A[0].first;
	for (int i = 1; i < N; i++) {
		if (A[i].second < r) {
			continue;
		}
		ans += A[i].second - max(A[i].first, r);
		r = A[i].second;
	}
	printf("%d", ans);
}