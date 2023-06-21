using namespace std;
#include <cstdio>

/*
{ 0 },
{ 1 },
{ 2, 4, 8, 6 },
{ 3, 9, 7, 1 },
{ 4, 6 },
{ 5 },
{ 6 },
{ 7, 9, 3, 1 },
{ 8, 4, 2, 6 },
{ 9, 1 },
*/

int f(int a, int b)
{
	a %= 10;

	int x, q, i;

	x = a, q = 1;
	while (true) {
		x = (x * a) % 10;
		if (x == a)
			break;
		q++;
	}

	b %= q;
	if (b == 0)
		b += q;
	
	x = 1;
	for (int i = 0; i < b; i++) {
		x = (x * a) % 10;
	}

	if (x == 0)
		return 10;
	return x;
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