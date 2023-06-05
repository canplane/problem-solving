using namespace std;
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

int ccw(pair<long, long> a, pair<long, long> b, pair<long, long> c)
{
	long ret = (b.first - a.first) * (c.second - a.second) - (b.second- a.second) * (c.first - a.first);
	if (ret > 0)	return 1;
	if (ret < 0)	return -1;
	return 0;
}
int intersect(pair<long, long> a, pair<long, long> b, pair<long, long> c, pair<long, long> d)
{
	auto [x1, y1] = a; auto [x2, y2] = b; auto [x3, y3] = c; auto [x4, y4] = d;
	long P = (x4 - x3) * (y2 - y1) - (x2 - x1) * (y4 - y3);
	return !!P;
}
int solve(pair<long, long> A, pair<long, long> B, pair<long, long> C, pair<long, long> D)
{
	int ans1 = ccw(A, B, C) * ccw(A, B, D);
	int ans2 = ccw(C, D, A) * ccw(C, D, B);

	int ans;
	if (ans1 == 0 && ans2 == 0) {
		if (intersect(A, B, C, D))
			ans = 1;
		else {
			if (A == D || B == C)
				ans = 1;
			else if (A < D && C < B)
				ans = 8;
			else
				ans = 0;
		}
	}
	else if (ans1 <= 0 && ans2 <= 0) {
		if (ans1 == 0)
			ans = 1;
		else
			ans = 2;
	}
	else
		ans = 0;
	return ans;
}

int main()
{
	int T;
	scanf("%d", &T);

	while (T--) {
		pair<long, long> C, D, A, B;
		scanf("%ld %ld", &C.first, &C.second);
		scanf("%ld %ld", &D.first, &D.second);
		scanf("%ld %ld", &A.first, &A.second);
		scanf("%ld %ld", &B.first, &B.second);
		if (A > B)  swap(A, B);

		int ans = 0;
		ans += solve(A, B, { C.first, C.second }, { D.first, C.second });
		ans += solve(A, B, { C.first, D.second }, { D.first, D.second });
		ans += solve(A, B, { C.first, C.second }, { C.first, D.second });
		ans += solve(A, B, { D.first, C.second }, { D.first, D.second });
		printf("%d\n", min(4, ans / 2));
	}
}