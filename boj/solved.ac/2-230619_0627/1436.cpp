/*
666
1666
2666
3666
4666
5666
6661
6662
6663
6664
6665
6666
7666
8666
9666
*/

#include <cstdio>

int main()
{
	int N;
	scanf("%d", &N);

	int n = 0, k = 0;
	while (k != N) {
		n++;
		for (int i = n; i; i /= 10) {
			if (i % 1000 == 666) {
				k++;
				break;
			}
		}
	}
	printf("%d", n);
}