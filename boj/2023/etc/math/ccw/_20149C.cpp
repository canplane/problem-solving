using namespace std;
#include <cstdio>
#include <utility>
#include <algorithm>

int ccw(pair<long, long> a, pair<long, long> b, pair<long, long> c)
{
	long ret = (b.first - a.first) * (c.second - a.second) - (b.second- a.second) * (c.first - a.first);
	return (int)max(min(ret, -1L), 1L); 
}

void find_intersect(pair<long, long> a, pair<long, long> b, pair<long, long> c, pair<long, long> d)
{
	auto [x1, y1] = a; auto [x2, y2] = b; auto [x3, y3] = c; auto [x4, y4] = d;

	long dx1 = x2 - x1, dy1 = y2 - y1;
	long dx3 = x4 - x3, dy3 = y4 - y3;
	long Px = dx1 * (x4 * y3 - y4 * x3) - dx3 * (x2 * y1 - y2 * x1);
	long Py = dy1 * (x4 * y3 - y4 * x3) - dy3 * (x2 * y1 - y2 * x1);
	long P = dx3 * dy1 - dx1 * dy3;

	if (P == 0) {
		if (a == d) {
			printf("%ld %ld\n", a.first, a.second);
		}
		else if (b == c) {
			printf("%ld %ld\n", c.first, c.second);
		}
	}
	else {
		printf("%.10lf %.10lf\n", (double)Px / P, (double)Py / P);
	}    
}

int main()
{
	pair<long, long> A, B, C, D;
	scanf("%ld %ld", &A.first, &A.second);
	scanf("%ld %ld", &B.first, &B.second);
	scanf("%ld %ld", &C.first, &C.second);
	scanf("%ld %ld", &D.first, &D.second);

	if (A > B)  swap(A, B);
	if (C > D)  swap(C, D);

	int ans1 = ccw(A, B, C) * ccw(A, B, D);
	int ans2 = ccw(C, D, A) * ccw(C, D, B);

	if (ans1 == 0 && ans2 == 0) {
		if (A <= D && C <= B) {
			printf("1\n");
			find_intersect(A, B, C, D);
		}
		else {
			printf("0\n");
		}
	}
	else if (ans1 <= 0 && ans2 <= 0) {
		printf("1\n");
		find_intersect(A, B, C, D);
	}
	else {
		printf("0\n");
	}
}