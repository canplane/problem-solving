// 트리맵의 범위를 넘어가면 맵이나 셋을 사용하지 말라고 권장하고 있다고 한다.

#include <cstdio>
#include <unordered_map>

int A[4000], B[4000], C[4000], D[4000], N;
long long ans;
std::unordered_map<int, int> AB;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			AB[A[i] + B[j]]++;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans += AB[-(C[i] + D[j])];
	printf("%lld", ans);
}