// BOJ 13701 G4 중복 제거

#include <cstdio>
#define SZ (1 << 22)

char vis[SZ];

int main()
{
	int x;
	while (scanf("%d", &x) == 1) {
		int i = x / 8, j = x % 8;
		if (!(vis[i] & (1 << j))) {
			printf("%d ", x);
		}
		vis[i] |= (1 << j);
	}
}