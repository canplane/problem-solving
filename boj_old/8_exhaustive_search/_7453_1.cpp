// lower_bound, upper_bound 따로 쓰는 것보단 equal_range 하나 쓰는 게 더 빠르다!

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[4000], B[4000], C[4000], D[4000], N;
long long ans;
vector<int> AB;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			AB.push_back(A[i] + B[j]);
	sort(AB.begin(), AB.end());
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			auto [low, high] = equal_range(AB.begin(), AB.end(), -(C[i] + D[j]));
			ans += high - low;
		}
	printf("%lld", ans);
}
