/* prefix sum (누적 합)

틀린 이유:
	1. overflow: (1 << i) -> (1L << i)
	2. math.log2가 실수라 정확치 않게 나옴. 직접 구현해야 한다.
*/

#include <cstdio>
#define _2(i) (1L << (i))

long S[55];

long f(long x)
{
	if (x == 0)	return 0;
	
	// i = log2(x)
	int i = 0;
	while (!(x < _2(i + 1)))	i++;

	// count([0, x]) = count([0, 2^i)) + count([2^i, x])
	return S[i] + ((x - _2(i) + 1) + f(x % _2(i)));
}

int main()
{
	for (int i = 1; i < 55; i++) {
		S[i] = _2(i - 1) + 2 * S[i - 1];
	}

	long A, B;
	scanf("%ld %ld", &A, &B);
	printf("%ld", f(B) - f(A - 1));
}