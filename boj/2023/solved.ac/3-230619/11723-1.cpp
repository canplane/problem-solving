#include <cstdio>
#include <cstring>

bool d[21];

int main()
{
	int M;
	scanf("%d", &M);
	while (M--) {
		char cmd[11]; int x;
		scanf("%s %d", cmd, &x);
		if (!strcmp(cmd, "add")) {
			d[x] = 1;
		}
		else if (!strcmp(cmd, "remove")) {
			d[x] = 0;
		}
		else if (!strcmp(cmd, "check")) {
			printf("%d\n", d[x]);
		}
		else if (!strcmp(cmd, "toggle")) {
			d[x] = !d[x];
		}
		else if (!strcmp(cmd, "all")) {
			memset(d, 1, sizeof(d));
		}
		else {	// empty
			memset(d, 0, sizeof(d));
		}
	}
}