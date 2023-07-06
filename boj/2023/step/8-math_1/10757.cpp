#include <cstdio>
#include <cstring>

char buf[10003];
int A[10001], B[10001], C[10002];

int main()
{
	int i = 0;

	scanf("%s", buf);
	int lA = strlen(buf);
	for (i = 0; i < lA; i++)
		A[i] = buf[lA - 1 - i] - '0';
	
	scanf("%s", buf);
	int lB = strlen(buf); 
	for (i = 0; i < lB; i++)
		B[i] = buf[lB - 1 - i] - '0';

	int s, c = 0;
	for (i = 0; i < lA || i < lB || c > 0; i++) {
		s = 0;
		if (A[i] > 0)
			s += A[i];
		if (B[i] > 0)
			s += B[i];
		if (c > 0)
			s += c;
		c = s / 10;
		C[i] = s % 10;
	}
	int lC = i;
	for (i = 0; i < lC; i++)
		buf[i] = C[lC - 1 - i] + '0';
	buf[lC] = '\0';
	
	printf("%s", buf);
}