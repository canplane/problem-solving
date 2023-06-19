// 분할 정복을 이용한 거듭제곱

#include <cstdio>

long A, B, C;

long dc(long B)
{
	if (B == 1) {
		return A % C;
	}
	long x = dc(B / 2);
	return (((x * x) % C) * (B % 2 ? A : 1)) % C;
}

int main()
{
	scanf("%ld %ld %ld", &A, &B, &C);
	printf("%ld", dc(B));
}