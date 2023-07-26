#include <cstdio>
#include <algorithm>

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);

	while (K) {
		if (N / 2 >= M) {
			N--;
		}
		else {
			M--;
		}
		K--;
	}
	printf("%d", std::min(N / 2, M));
}