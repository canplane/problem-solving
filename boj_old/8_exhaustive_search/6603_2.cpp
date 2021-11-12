#include <cstdio>

int num[13], rst[6], k;

void dfs(int pos, int idx) {
	if (pos == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", rst[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i < k; i++) {
		rst[pos] = num[i];
		dfs(pos + 1, i + 1);
	}
}

int main() {
	while (true) {
		scanf("%d", &k);
		if (!k)
			break;
		for (int i = 0; i < k; i++)
			scanf("%d", &num[i]);
		dfs(0, 0), printf("\n");
	}
}