// https://velog.io/@jxlhe46/백준-2293번.-동전-1-bfi120m5

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
		for (int j = W[i]; j <= k; j++) {
			F[j] += F[j - W[i]];
		}
	}
	printf("%d", F[k]);
}