/* divide-conquer method: O(nlgn) */

using namespace std;
#include <cstdio>
#include <algorithm>

long h[100000];
int N;

long f(int l, int r)
{
	if (l + 1 == r)		return h[l];
	
	int m = (l + r) / 2;
	long side = max(f(l, m), f(m, r));

	int i = m - 1, j = m;
	long span_h = min(h[i--], h[j++]);
	long span = span_h * (j - i - 1);
	while (l <= i && j < r) {
		span_h = min(span_h, h[i] > h[j] ? h[i--] : h[j++]);
		span = max(span, span_h * (j - i - 1));
	}
	while (l <= i) {
		span_h = min(span_h, h[i--]);
		span = max(span, span_h * (j - i - 1));
	}
	while (j < r) {
		span_h = min(span_h, h[j++]);
		span = max(span, span_h * (j - i - 1));
	}

	return max(side, span);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%ld", &h[i]);

	printf("%ld", f(0, N));
}