using namespace std;
#include <cstdio>
#include <algorithm>
#include <cmath>

int A[8], I[8];

double X[8], Y[8];
double ccw(int i, int j, int k)
{
	double x1 = X[j] - X[i], y1 = Y[j] - Y[i], x2 = X[k] - X[j], y2 = Y[k] - Y[j];
	return x1 * y2 - y1 * x2;
}
int main()
{
	for (int i = 0; i < 8; i++) {
		scanf("%d", &A[i]);
		I[i] = i;
	}

	int ans = 0;
	do {
		bool valid = true;
		for (int i = 0; i < 8; i++) {
			X[i] = cos(M_PI * i / 4) * A[I[i]], Y[i] = sin(M_PI * i / 4) * A[I[i]];
		}
		for (int i = 0; i < 8; i++) {
			if (!(ccw(i, (i + 1) % 8, (i + 2) % 8) > 0)) {
				valid = false;
				break;
			}
		}
		ans += valid;
	} while (next_permutation(I, I + 8));
	printf("%d", ans);
}