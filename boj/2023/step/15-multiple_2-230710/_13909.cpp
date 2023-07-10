#include <cstdio>

// N보다 작은 자연수 중 약수 개수가 홀수인 개수
// (n1 + 1)(n2 + 1)... -> n1, n2, ...가 모두 짝수여야 함
// 즉 N보다 작은 자연수 중 제곱수의 개수

int main()
{
	int N;
	scanf("%d", &N);

	int cnt = 0;
	for (int i = 1; i * i <= N; i++) {
		cnt++;
	}
	printf("%d", cnt);
}