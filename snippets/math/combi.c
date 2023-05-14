#include <stdio.h>

int _c[21];
void combi(int n, int r, int left, int pos)
{
	if (pos == r) {
		for (int i = 0; i < r; i++) printf("%d ", _c[i]);
		puts("");
		return;
	}
	if (left == n)  return;

    for (int i = left; i < n; i++) {
		_c[pos] = i;
		combi(n, r, i + 1, pos + 1);
	}
}

int main()
{
    combi(4, 2, 0, 0);
}