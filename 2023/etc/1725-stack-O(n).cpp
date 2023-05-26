/* stack method: O(n) */

using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

int main()
{
	int n;
	scanf("%d", &n);

	vector<pair<long, int>> s;
	long ans = 0;
	int i;
	for (i = 0; i <= n; i++) {
		long h;
		if (i == n)
			h = 0;
		else
			scanf("%ld", &h);

		int j = i;
		while (s.size()) {
			auto [h1, i1] = s.back();
			if (h > h1)	break;
			s.pop_back();
			j = i1;
			ans = max(ans, h1 * (i - i1));
		}
		s.push_back({ h, j });
	}
	printf("%ld\n", ans);
}