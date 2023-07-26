using namespace std;
#include <cstdio>
#include <tuple>
#include <set>

int A, B, C;

set<tuple<int, int, int>> visit;
set<int> ans;
void dfs(tuple<int, int, int> v)
{
	if (visit.find(v) != visit.end())
		return;

	visit.insert(v);
	auto [a, b, c] = v;
	if (a == 0)
		ans.insert(c);
	
	int d;
	if (a > 0) {
		d = min(B - b, a), dfs({ a - d, b + d, c });
		d = min(C - c, a), dfs({ a - d, b, c + d });
	}
	if (b > 0) {
		d = min(A - a, b), dfs({ a + d, b - d, c });
		d = min(C - c, b), dfs({ a, b - d, c + d });
	}
	if (c > 0) {
		d = min(A - a, c), dfs({ a + d, b, c - d });
		d = min(B - b, c), dfs({ a, b + d, c - d });
	}
}

int main()
{
	scanf("%d %d %d", &A, &B, &C);
	dfs({ 0, 0, C });
	for (int x : ans)
		printf("%d ", x);
}