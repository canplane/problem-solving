// 이분 탐색
// 백준도 운이 나쁘면 맞는 게 시간 초과를 내는 듯.

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
			auto lower = lower_bound(AB.begin(), AB.end(), -(C[i] + D[j]));
			auto upper = upper_bound(AB.begin(), AB.end(), -(C[i] + D[j]));
			ans += upper - lower;  // distance(lower, upper);
		}
	printf("%lld", ans);
}