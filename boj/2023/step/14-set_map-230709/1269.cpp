#include <bits/stdc++.h>

int n, m, x;
std::set<int> dic;

int main()
{
	scanf("%d %d", &n, &m);
	n += m;
	while (n--) {
		scanf("%d", &x);
		auto [y, b] = dic.insert(x);
		if (!b) {
			dic.erase(x);
		}
	}
	printf("%ld", dic.size());
}