#include <cstdio>

int map[9][9], node[81], node_sz;

bool dfs(int idx) {
	if (idx == node_sz)
		return true;

	int y = node[idx] / 9, x = node[idx] % 9;
	bool candi[10];
	for (int i = 1; i < 10; i++)
		candi[i] = true;

	for (int i = 0; i < 9; i++) {
		candi[map[y][i]] = candi[map[i][x]] = false;
		candi[map[3 * (y / 3) + i / 3][3 * (x / 3) + i % 3]] = false;
	}
	for (int i = 1; i < 10; i++) {
		if (candi[i]) {
			map[y][x] = i;
			if (dfs(idx + 1))
				return true;
		}
	}
	map[y][x] = 0;
	return false;
}

int main() {
	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			scanf("%d", &map[y][x]);

	for (int y = 0; y < 9; y++)
		for (int x = 0; x < 9; x++)
			if (!map[y][x])
				node[node_sz++] = 9 * y + x;
	dfs(0);

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++)
			printf("%d ", map[y][x]);
		printf("\n");
	}
}