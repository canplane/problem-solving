using namespace std;
#include <cstdio>
#include <utility>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);

	int xm, xM, ym, yM;
	int x, y;

	scanf("%d %d", &x, &y);
	xm = xM = x, ym = yM = y;
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &x, &y);
		xm = min(xm, x), xM = max(xM, x), ym = min(ym, y), yM = max(yM, y);
	}
	printf("%d", (xM - xm) * (yM - ym));
}