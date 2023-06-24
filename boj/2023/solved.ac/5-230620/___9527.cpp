using namespace std;
#include <cstdio>

/*
000
001
010
011
100
101
110
111
*/

long f(long a, long b, long n)
{
	long a_l = a / n * n;
	long b_r = (b / n + 1) * n;

	long cnt = (b_r - a_l) / 2;

	long a_m = a_l + n / 2;
	if (a_m < a) {
		cnt -= a - a_m;
	}

	long b_m = b_r - n / 2;
	if (b < b_m) {
		cnt -= n / 2;
	}
	else {
		cnt -= (b_r - (b + 1));
	}

	return cnt;
}

int main()
{
	long A, B;
	scanf("%ld %ld", &A, &B);
	
	long ans = 0;
	for (int i = 1; i < 63; i++) {
		ans += f(A, B, 1L << i);
	}
	printf("%ld", ans);
}