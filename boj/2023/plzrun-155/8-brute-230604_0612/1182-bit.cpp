/* 10배는 더 느리다. (중간 결과 저장 없이 매번 계산해서) */

#include <cstdio>
#include <cmath>

int N, S;
int A[20];

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	
	int cnt = 0;
	for (int x = 1; x < (int)pow(2, N); x++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (x & (1 << i))
				sum += A[i];
		}
		cnt += (sum == S);
	}
	printf("%d", cnt);
}