// 시간 초과 : 1씩 더해 나가면 너무 많다.

/*
<x:y>이 n번째 해라면,
1 + (n - 1) % M = x, 1 + (n - 1) % N = y
*/

using namespace std;
#include <cstdio>

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

		int n = 1;
		int max_n = M * N / gcd(M, N);
		while (n <= max_n) {
			if ((n - 1) % M + 1 == x && (n - 1) % N + 1 == y) {
				break;
			}
			n++;
		}
		printf("%d\n", n == max_n + 1 ? -1 : n);
	}
}