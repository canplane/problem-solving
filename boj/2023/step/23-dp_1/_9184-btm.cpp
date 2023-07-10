#include <cstdio>

int w[51][51][51];
int W(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return w[20][20][20];
	}
	return w[a][b][c];
}

int main()
{
	for (int a = 0; a <= 50; a++) {
		for (int b = 0; b <= 50; b++) {
			for (int c = 0; c <= 50; c++) {
				if (a < b && b < c) {
					w[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
				}
				else {
					w[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
				}
			}
		}
	}

	while (true) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}
}