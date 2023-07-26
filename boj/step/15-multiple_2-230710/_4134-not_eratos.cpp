#include <cstdio>

bool is_prime(long N)
{
	if (N < 2) {
		return false;
	}
	for (long i = 2; i * i <= N; i++) {	// O(sqrt(N))
		if (N % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		long N;
		scanf("%ld", &N);
		for (; !is_prime(N); N++);
		printf("%ld\n", N);
	}
}