#include <cstdio>

int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if (A + B + C != 180)
		puts("Error");
	else if (A == B && B == C)
		puts("Equilateral");
	else if (A == B || B == C || C == A)
		puts("Isosceles");
	else
		puts("Scalene");
}