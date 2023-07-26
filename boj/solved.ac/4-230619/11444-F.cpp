using namespace std;
#include <cstdio>
#include <utility>

// 실패 : 나누기가 중간에 있으면 모듈러 분배 법칙 정상적으로 동작 안 함.
// [반례] MOD가 5라 하면 이상하게 나온다.
#define MOD 1'000'000'007

pair<long, long> mul(pair<long, long> a, pair<long, long> b)
{
	auto [ar, ai] = a; auto [br, bi] = b;
	long cr = ((ar * br + 5 * ai * bi) / 2) % MOD;
	long ci = ((ar * bi + ai * br) / 2) % MOD;
	return { cr, ci };
}
pair<long, long> dc(long n)
{
	if (n == 0)
		return { 2, 0 };
	if (n == 1)
		return { 1, 1 };

	pair<long, long> p = dc(n / 2);
	return mul(mul(p, p), dc(n % 2));
}
long pibo(long n)
{
	pair<long, long> a = dc(n);
	return a.second;
}

int main()
{
	long n;
	scanf("%ld", &n);
	printf("%ld", pibo(n));
}