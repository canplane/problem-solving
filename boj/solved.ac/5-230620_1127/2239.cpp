using namespace std;
#include <cstdio>
#include <vector>
#include <utility>

int A[9][9];
vector<pair<int, int>> zeros;

void make_candi(bool candi[], int y0, int x0)
{
	for (int i = 1; i <= 9; i++) {
		candi[i] = true;
	}
	
	int y, x;
	for (y = 0; y < 9; y++) {
		candi[A[y][x0]] = false;
	}
	for (x = 0; x < 9; x++) {
		candi[A[y0][x]] = false;
	}
	y = y0 / 3 * 3, x = x0 / 3 * 3;
	for (int dy = 0; dy < 3; dy++) {
		for (int dx = 0; dx < 3; dx++) {
			candi[A[y + dy][x + dx]] = false;
		}
	}
}
bool dfs(int idx)
{
	if (idx == zeros.size()) {
		return true;
	}

	auto [y0, x0] = zeros[idx];

	bool candi[10];
	make_candi(candi, y0, x0);
	
	for (int i = 1; i <= 9; i++) {
		if (candi[i]) {
			A[y0][x0] = i;
			if (dfs(idx + 1)) {
				return true;
			}
			A[y0][x0] = 0;
		}
	}
	return false;
}

int main()
{
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%1d", &A[y][x]);
			if (!A[y][x]) {
				zeros.push_back({ y, x });
			}
		}
	}
	
	dfs(0);

	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			printf("%d", A[y][x]);
		}
		printf("\n");
	}
}