#include <cstdio>
#include <algorithm>

int v[13], k;

void dfs(int idx) {
	if (idx == 6) {
		bool sense = true;
		for (int i = 0; i < 6 - 1; i++)
			if (!(v[i] <= v[i + 1])) {
				sense = false;
				break;
			}
		if (sense) {
			for (int i = 0; i < 6; i++)
				printf("%d ", v[i]);
			printf("\n");
		}
		return;
	}

	for (int i = idx; i < k; i++) {
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