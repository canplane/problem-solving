// 552 ms

#include <cstdio>

bool is_prime(int x)
{
	if (x < 2) {
		return false;
	}
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int main()
{
	while (true) {
		int N;
		scanf("%d", &N);
		if (N == 0) {
			break;
		}

		int cnt = 0;
		for (int x = N + 1; x <= 2 * N; x++) {
			cnt += is_prime(x);
		}
		printf("%d\n", cnt);
	}
}