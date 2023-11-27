using namespace std;
#include <bits/stdc++.h>

int N;
vector<pair<int, int>> candidates;
bool unsafe[10][10];

void _mark(vector<pair<int, int>> &v, int y, int x)
{
	if ((0 <= x && x < N) && !unsafe[y][x]) {
		unsafe[y][x] = true, v.push_back({ y, x });
	}
}
void mark(vector<pair<int, int>> &v, int y0, int x0)
{
	for (int y = 0, x; y < N; y++) {
		_mark(v, y, y + (x0 - y0));
		_mark(v, y, -y + (x0 + y0));
	}
}
void unmark(vector<pair<int, int>> &w)
{
	for (auto &[y, x] : w) {
		unsafe[y][x] = false;
	}
}

int bt(int i)
{
	int ret = 0;
	for (int j = i; j < candidates.size(); j++) {
		auto [y0, x0] = candidates[j];
		if (!unsafe[y0][x0]) {
			vector<pair<int, int>> v;
			mark(v, y0, x0);
			ret = max(ret, 1 + bt(j + 1));
			unmark(v);
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	
	int b;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &b);
			if (b) {
				candidates.push_back({ y, x });
			}
		}
	}

	printf("%d", bt(0));
}