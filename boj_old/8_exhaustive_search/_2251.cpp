#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<int> visit;
vector<int> v;

int A, B, C;

void dfs(int a, int b, int c) {
	int key = a * 1000000 + b * 1000 + c;
	if (!visit.insert(key).second)
		return;

	if (!a)
		v.push_back(c);

	int na, nb, nc;
	if (a > 0) {
		if (b < B)
			na = max(a + b, B) - B, nb = min(a + b, B), dfs(na, nb, c);
		if (c < C)
			na = max(a + c, C) - C, nc = min(a + c, C), dfs(na, b, nc);
	}
	if (b > 0) {
		if (c < C)
			nb = max(b + c, C) - C, nc = min(b + c, C), dfs(a, nb, nc);
		if (a < A)
			nb = max(b + a, A) - A, na = min(b + a, A), dfs(na, nb, c);
	}
	if (c > 0) {
		if (a < A)
			nc = max(c + a, A) - A, na = min(c + a, A), dfs(na, b, nc);
		if (b < B)
			nc = max(c + b, B) - B, nb = min(c + b, B), dfs(a, nb, nc);
	}
}

int main() {
	scanf("%d %d %d", &A, &B, &C);
	dfs(0, 0, C);
	sort(v.begin(), v.end());
	for (auto& d : v)
		printf("%d ", d);
}