#include <cstdio>
#include <algorithm>

int A[3];
int main()
{
	for (int i = 0; i < 3; i++)
		scanf("%d", &A[i]);
	std::sort(A, A + 3);
	printf("%d", A[0] + A[1] + std::min(A[2], A[0] + A[1] - 1));
}