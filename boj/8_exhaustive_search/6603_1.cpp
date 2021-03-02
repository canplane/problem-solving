#include <cstdio>
#include <algorithm>

int v[13], k;

void dfs(int idx) {
	if (idx == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", v[i]);
		printf("\n");
		return;
	}
	for (int i = idx; i < k; i++) {
		if (idx > 0 && !(v[idx - 1] < v[i]))
			continue;
		std::swap(v[idx], v[i]);
		dfs(idx + 1);
		std::swap(v[idx], v[i]);
	}
}

int main() {
	while (true) {
		scanf("%d", &k);
		if (!k)
			break;
		for (int i = 0; i < k; i++)
			scanf("%d", &v[i]);
		dfs(0), printf("\n");
	}
}