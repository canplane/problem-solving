#include <bits/stdc++.h>
#define p ((int *)B)

int d, l = 1 << 30;
long A[1 << 20], *B = A;

int main()
{
	scanf("%*d");
	while (~scanf("%d%d", B++, p + 1));
	std::sort(A, B);

	while (B --> A)	*p < l && (d += std::min(p[1], l) - (l = *p));
	printf("%d", d);
}