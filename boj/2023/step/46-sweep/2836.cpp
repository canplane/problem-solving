using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

vector<pair<int, int>> back;

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	while (N--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x > y) {
			back.push_back({ y, x });
		}
	}
	sort(begin(back), end(back));

	long ans; int r;
	ans = back[0].second - back[0].first, r = back[0].second;
	for (int i = 1; i < back.size(); i++) {
		if (back[i].second > r) {
			ans += back[i].second - max(back[i].first, r);
			r = back[i].second;
		}
	}
	ans = M + 2 * ans;
	printf("%ld", ans);
}