#include <stdio.h>

char s[501], t[501];
int l, l0, l1;
int i, j;

int main()
{
	scanf("%s", s);
	for (; s[l]; l++)
		if (s[l] == '0')	l0++;
		else				l1++;
	l0 /= 2, l1 /= 2;

	for (; i < l; i++) {
		if (s[i] == '0') {
			if (l0)			l0--, t[j++] = s[i];
		}
		else if (s[i] == '1') {
			if (l1)			l1--;
			else			t[j++] = s[i];
		}
	}
	printf("%s", t);
}