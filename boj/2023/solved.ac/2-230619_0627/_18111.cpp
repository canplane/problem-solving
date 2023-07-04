#include <cstdio>

int N, M, B;
int H[500][500];

int f(int h)
{
	int lo = 0, hi = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (H[y][x] <= h)
				lo += h - H[y][x];
			else
				hi += H[y][x] - h;
		}
	}
	return B + hi - lo >= 0 ? lo + 2 * hi : -1;
}
int main()
{
	scanf("%d %d %d", &N, &M, &B);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			scanf("%d", &H[y][x]);
	}

	unsigned ans_t = -1, ans_h, t;
	for (int h = 256; h >= 0; h--) {
		if ((t = f(h)) < ans_t)
			ans_t = t, ans_h = h;
	}
	printf("%d %d", ans_t, ans_h);
}