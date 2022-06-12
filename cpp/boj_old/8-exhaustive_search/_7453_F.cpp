#include <cstdio>
#include <unordered_map>

int A[4000], B[4000], C[4000], D[4000], N;
long long ans;
std::unordered_map<int, int> AB, CD;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			AB[A[i] + B[j]]++, CD[C[i] + D[j]]++;
	for (auto it = AB.begin(); it != AB.end(); it++)
		ans += it->second * CD[-it->first];
	printf("%lld", ans);
}
