#include <cstdio>

int n;
int preord[1000], inord[1000];

void postord(int lp, int rp, int li, int ri)
{
	if (lp == rp) {
		return;
	}
	int x = preord[lp];
	int d;
	for (d = 0; li + d < ri; d++) {
		if (inord[li + d] == x) {
			break;
		}
	}
	postord(lp + 1, (lp + 1) + d, li, li + d);
	postord((lp + 1) + d, rp, (li + d) + 1, ri);
	printf("%d ", x);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &preord[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &inord[i]);
		}
		postord(0, n, 0, n), printf("\n");
	}
}