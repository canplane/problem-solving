#include <cstdio>

int N, M;
int A[10000];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int i = 0, j = 0;
	int sum = 0;
	int cnt = 0;
	while (j <= N) {
		cnt += (sum == M);		
		if (sum <= M)
			sum += A[j++];
		else
			sum -= A[i++];
	}
	printf("%d", cnt);
}