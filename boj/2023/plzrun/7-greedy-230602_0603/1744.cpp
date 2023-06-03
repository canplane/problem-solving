/*

	1이 있으면 그냥 더한다.

	(-) 두 개 있으면 곱한다.
	(+) (> 1) 두 개 있으면 곱한다.
	(-), 0 있으면 곱한다.
*/


using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> pos, neg;
	int ans = 0;

	int x;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x == 1)
			ans += x;
		else if (x > 1)
			pos.push_back(x);
		else
			neg.push_back(x);
	}

	sort(pos.begin(), pos.end(), greater());
	pos.push_back(1);
	for (int i = 0; i + 1 < pos.size(); i += 2) {
		ans += pos[i] * pos[i + 1];
	}
	sort(neg.begin(), neg.end());
	neg.push_back(1);
	for (int i = 0; i + 1 < neg.size(); i += 2) {
		ans += neg[i] * neg[i + 1];
	}
	printf("%d", ans);
}
