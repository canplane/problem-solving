#include <cstdio>
#include <algorithm>
using namespace std;

int N;
int LIS[1'000'000], len_LIS;

int main()
{
	int x;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		
		auto it = lower_bound(LIS, LIS + len_LIS, x);
		if (it == LIS + len_LIS)
			len_LIS += 1;
		*it = x;
	}
	printf("%d", len_LIS);
}