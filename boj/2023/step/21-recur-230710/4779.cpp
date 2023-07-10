#include <cstdio>

void f(int l, int r, bool hyp)
{
	if (l + 1 == r) {
		printf("%c", hyp ? '-' : ' ');
		return;
	}
	int dx = (r - l) / 3;
	f(l, l + dx, hyp), f(l + dx, r - dx, false), f(r - dx, r, hyp);
}

int main()
{
	int N;
	while (scanf("%d", &N) == 1) {
		int x = 1;
		for (int i = 0; i < N; i++)	x *= 3;
		f(0, x, true), puts("");
	}
}