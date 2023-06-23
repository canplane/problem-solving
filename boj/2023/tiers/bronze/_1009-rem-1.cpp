#include <cstdio>

int f(int a, int b)
{
	a %= 10;
	int x = a, c = 1;
	while ((x = (x * a) % 10) != a) {
		c++;
	}
	b = (b + (c - 1)) % c + 1;
	
	x = 1;
	for (int i = 0; i < b; i++) {
		x = (x * a) % 10;
	}
	return (x + (10 - 1)) % 10 + 1;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", f(a, b));
	}
}