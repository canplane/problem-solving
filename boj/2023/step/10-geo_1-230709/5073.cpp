#include <cstdio>

int main()
{
	while (true) {
		int A, B, C;
		scanf("%d %d %d", &A, &B, &C);
		if (A == 0)
			break;
		
		if (A + B <= C || B + C <= A || C + A <= B)
			puts("Invalid");
		else if (A == B && B == C)
			puts("Equilateral");
		else if (A == B || B == C || C == A)
			puts("Isosceles");
		else
			puts("Scalene");
	}
}