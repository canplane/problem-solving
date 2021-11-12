#include <cstdio>
#include <vector>
#include <utility>

int map[9][9];

std::vector<std::pair<int, int>> v;

bool dfs(int idx) {
	if (idx == v.size())
		return true;

	auto [y, x] = v[idx];
	bool candidates[10];
	for (int i = 1; i < 10; i++)
		candidates[i] = true;

	for (int i = 0; i < 9; i++) {
		candidates[map[y][i]] = candidates[map[i][x]] = false;
		candidates[map[3 * (y / 3) + i / 3][3 * (x / 3) + i % 3]] = false;
	}
	for (int i = 1; i < 10; i++) {
		if (candidates[i]) {
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
				v.push_back({ y, x });
	dfs(0);

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++)
			printf("%d ", map[y][x]);
		printf("\n");
	}
}