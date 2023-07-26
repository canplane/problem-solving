#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a % 10 == 0) {
			printf("10\n");
		}
		else {
			int ans = 1;
			for (int i = 0; i < b; i++) {
				ans = (ans * a) % 10;
			}
			printf("%d\n", ans);
		}
	}
}