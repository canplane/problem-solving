#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int A[1'000'000];
int bs[1'000'000], len_bs;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);

		auto it = lower_bound(bs, bs + len_bs, x);
		if (it == bs + len_bs)
			len_bs += 1;
		*it = x;
	}
	printf("%d", len_bs);
}