#include <stdio.h>
#include <string.h>

char buf[100];

int N;
int stack[100000], sz;

char s[100];
int x;

int main()
{
	fgets(buf, 100, stdin), sscanf(buf, "%d", &N);
	while (N--) {
		fgets(buf, 100, stdin), sscanf(buf, "%s %d", s, &x);
		if (!strcmp(s, "push")) {
			stack[sz++] = x;
		}
		else if (!strcmp(s, "pop")) {
			x = sz ? stack[--sz] : -1;
			printf("%d\n", x);
		}
		else if (!strcmp(s, "top")) {
			x = sz ? stack[sz - 1] : -1;
			printf("%d\n", x);
		}
		else if (!strcmp(s, "size")) {
			printf("%d\n", sz);
		}
		else if (!strcmp(s, "empty")) {
			printf("%d\n", !sz);
		}
		else {
			printf("???\n");
		}
	}
}