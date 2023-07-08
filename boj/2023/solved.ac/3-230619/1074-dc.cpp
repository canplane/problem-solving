using namespace std;
#include <cstdio>

int N, r, c;
int dc(int y0, int x0, int d)
{
	if (d == 1) {
		return 0;
	}
	int d2 = d / 2;
	int i0 = (r - y0) / d2, j0 = (c - x0) / d2;
	return (i0 * 2 + j0) * (d2 * d2) + dc(y0 + i0 * d2, x0 + j0 * d2, d2);
}

int main()
{
	scanf("%d %d %d", &N, &r, &c);
	printf("%d", dc(0, 0, 1 << N));
}