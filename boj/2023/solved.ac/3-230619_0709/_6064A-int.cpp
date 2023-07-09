using namespace std;
#include <cstdio>
#include <algorithm>

int gcd(int a, int b)
{
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int M, N, x, y;
		scanf("%d %d %d %d", &M, &N, &x, &y);

		if (!(M <= N)) {
			swap(M, N), swap(x, y);
		}

		int lcm = M * N / gcd(M, N);
		int n;
		for (n = y; n <= lcm; n += N) {
			if ((n - 1) % M == x - 1) {
				break;
			}
		}
		printf("%d\n", n > lcm ? -1 : n);
	}
}