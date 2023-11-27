// BOJ 1799 G1 비숍
// 그냥 백트래킹하면 100! = 100^100 -> 시간 초과. 반 나눠서 50! + 50!으로 풀어야 함.

using namespace std;
#include <bits/stdc++.h>

int N;
vector<pair<int, int>> v[2];

int rb[20], lb[20];
#define RB rb[N + (y - x)]  // 우하단 사선에서 점유 유무
#define LB lb[y + x]  // 좌하단 사선에서 점유 유무

int bt(int odd, int i)
{
	int ret = 0;
	for (int j = i; j < v[odd].size(); j++) {
		auto [y, x] = v[odd][j];
		if (!RB && !LB) {
			RB = LB = 1;
			ret = max(ret, 1 + bt(odd, j + 1));
			RB = LB = 0;
		}
	}
	return ret;
}

int main()
{
	int b;

	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &b);
			if (b) {
				v[(y + x) % 2].push_back({ y, x });
			}
		}
	}
	printf("%d", bt(0, 0) + bt(1, 0));
}