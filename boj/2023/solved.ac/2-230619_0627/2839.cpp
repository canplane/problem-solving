// 5a + 3b = N

#include <cstdio>

int f(int N)
{
	for (int b = 0; 3 * b <= N; b++) {
		int a = (N - 3 * b) / 5;
		if (5 * a + 3 * b == N) {
			return a + b;
		}
	}
	return -1;
}

int main()
{
	int N;
	scanf("%d", &N);
	printf("%d", f(N));
}