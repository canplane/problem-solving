#include <cstdio>

// O(sqrt(N))
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
	int N;
	scanf("%d", &N);

	int ans = 0;
	while (N--) {
		int x;
		scanf("%d", &x);
		ans += is_prime(x);
	}
	printf("%d", ans);
}