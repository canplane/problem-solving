#include <cstdio>

int N;
int A[1000000];
int B, C;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d %d", &B, &C);

	long ans = 0;
	for (int i = 0; i < N; i++) {
		int a = A[i] - B;
		ans++;
		if (a >= 0) {
			ans += a / C + (a % C > 0);
		}
	}
	printf("%ld", ans);
}