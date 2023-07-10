#include <cstdio>

int w[51][51][51];
int W(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0) {
		return w[0][0][0] = 1;
	}
	if (a > 20 || b > 20 || c > 20) {
		return w[20][20][20] = W(20, 20, 20);
	}
	if (w[a][b][c]) {
		return w[a][b][c];
	}
	if (a < b && b < c) {
		return w[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
	}
	return w[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}

int main()
{
	while (true) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}
}