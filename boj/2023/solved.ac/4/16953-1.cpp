#include <cstdio>

int main()
{
	int A, B;
	scanf("%d %d", &A, &B);

	int ans = 1;
	while (A < B) {
		if (B % 10 == 1)
			B /= 10;
		else if (B % 2 == 0)
			B /= 2;
		else
			break;
		ans++;
	}
	printf("%d", A == B ? ans : -1);
}