#include <cstdio>

int n, k;
int W[101], F[10001];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &W[i]);
	
	F[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = k; j >= 0; j--) {
			// 그냥 k개 들어있는 건 j = k - W[i]일 때 계산했으면 될 일. 중복!
			for (int k = 1; j - k * W[i] >= 0; k++) {
				F[j] += F[j - k * W[i]];
			}
		}
	}
	printf("%d", F[k]);
}