using namespace std;
#include <cstdio>
#include <cmath>
#include <utility>

int N;
pair<long, long> A[10000];

long CCW(int i, int j, int k)
{
	auto [Ax, Ay] = A[i];
	auto [Bx, By] = A[j];
	auto [Cx, Cy] = A[k];
	return (Bx - Ax) * (Cy - Ay) - (By - Ay) * (Cx - Ax);
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		A[i] = { x, y };
	}

	double ans = 0;
	for (int i = 2; i < N; i++) {
		ans += (double)CCW(0, i - 1, i) / 2;
	}

	printf("%.1lf", abs(ans));
}