// 비트 연산자는 우선 순위가 낮다! 그냥 괄호로 묶어주는 게 좋다.

#include <cstdio>
#include <cstring>

int d;

int main()
{
	int M;
	scanf("%d", &M);
	while (M--) {
		char cmd[11]; int x;
		scanf(" %s %d", cmd, &x);
		if (!strcmp(cmd, "add")) {
			d |= (1 << x);
		}
		else if (!strcmp(cmd, "remove")) {
			d &= ~(1 << x);
		}
		else if (!strcmp(cmd, "check")) {
			printf("%d\n", (d & (1 << x)) == (1 << x));
		}
		else if (!strcmp(cmd, "toggle")) {
			d ^= (1 << x);
		}
		else if (!strcmp(cmd, "all")) {
			d = (1 << 21) - 2;
		}
		else {	// empty
			d = 0;
		}
	}
}