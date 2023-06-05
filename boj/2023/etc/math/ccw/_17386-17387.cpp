using namespace std;
#include <cstdio>
#include <utility>

int ccw(pair<long, long> a, pair<long, long> b, pair<long, long> c)
{
	long ret = (b.first - a.first) * (c.second - a.second) - (b.second- a.second) * (c.first - a.first);
	if (ret > 0)	return 1;
	if (ret < 0)	return -1;
	return 0;
}
bool intersect(pair<long, long> A, pair<long, long> B, pair<long, long> C, pair<long, long> D)
{
	int ans1 = ccw(A, B, C) * ccw(A, B, D);
	int ans2 = ccw(C, D, A) * ccw(C, D, B);
	
	if (ans1 == 0 && ans2 == 0)
		return A <= D && C <= B;
	else
		return ans1 <= 0 && ans2 <= 0;
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
	printf("%d", intersect(A, B, C, D));
}