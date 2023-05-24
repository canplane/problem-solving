#include <stdio.h>

char o[333335];

int main()
{
	scanf("%s", o);
	int d, i;
	{
		d = o[0] - '0';
		printf("%d", 100 * !!(d & 4) + 10 * !!(d & 2) + !!(d & 1));
	}
	for (i = 1; o[i]; i++) {
		d = o[i] - '0';
		printf("%03d", 100 * !!(d & 4) + 10 * !!(d & 2) + !!(d & 1));
	}
}