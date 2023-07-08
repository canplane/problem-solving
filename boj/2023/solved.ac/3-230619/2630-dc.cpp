using namespace std;
#include <cstdio>

int N;
int A[128][128];
int ans[2];

void dc(int y0, int x0, int d)
{
	int color = A[y0][x0];
	bool b = true;
	for (int y = y0; y < y0 + d; y++) {
		for (int x = x0; x < x0 + d; x++) {
			if (A[y][x] != color) {
				b = false;
				break;
			}
		}
	}
	if (b) {
		ans[color] += 1;
	}
	else {
		for (int y = y0; y < y0 + d; y += d / 2) {
			for (int x = x0; x < x0 + d; x += d / 2) {
				dc(y, x, d / 2);
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
		}
	}

	dc(0, 0, N);
	for (int i = 0; i < 2; i++) {
		printf("%d\n", ans[i]);
	}
}