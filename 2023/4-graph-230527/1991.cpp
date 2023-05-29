#include <cstdio>
#define g(j) i == j && putchar(v)

char A[99][5];
int i;

void f(char v) { v != '.' && ( g(2), f(A[v][1]), g(1), f(A[v][3]), g(0) ); }

int main()
{
	scanf("%d", &i);
	while (i--)	scanf(" %c", *A), fgets(A[**A], 5, stdin);
	i = 3;
	while (i--)	f('A'), puts("");
}