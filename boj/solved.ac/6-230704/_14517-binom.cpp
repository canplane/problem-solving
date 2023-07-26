using namespace std;
#include <cstdio>

#define SZ 4000001

#define MOD 1'000'000'007

long fact[SZ];
long po(long x, long n)
{
	if (n == 0) {
		return 1;
	}
	long ret = po(x, n / 2);
	ret = (ret * ret) % MOD;
	if (n % 2) {
		ret = (ret * x) % MOD;
	}
	return ret;
}
long binom(long n, long k)
{
	long nu = fact[n], de = (fact[k] * fact[n - k]) % MOD;
	return (nu * po(de, MOD - 2)) % MOD;
}
int main()
{
	fact[0] = 1;
	for (int n = 1; n < SZ; n++) {
		fact[n] = (n * fact[n - 1]) % MOD;
	}

	long M;
	scanf("%ld", &M);
	while (M--) {
		long N, K;
		scanf("%ld %ld", &N, &K);
		printf("%ld\n", binom(N, K));
	}
}