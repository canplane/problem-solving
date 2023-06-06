/* [5 -> 17]
5, 6, 7, 8, 16, 17
5, 4, 8, 16, 17
*/

using namespace std;
#include <cstdio>
#include <algorithm>

int N, K;

int f(int k)
{
	if (k <= N)
		return N - k;
	int ret = 1 + ((k % 2 && k != 1) ? min(f(k - 1), f(k + 1)) : f(k / 2));
	return min(ret, k - N);
}

int main()
{
	scanf("%d %d", &N, &K);
	printf("%d", f(K));
}