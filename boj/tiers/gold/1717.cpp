#include <cstdio>

int parent[1000001];
void dj_init(int n)
{
	for (int u = 1; u <= n; u++) {
		parent[u] = u;
	}
}
int dj_find(int u)
{
	int r = u;
	while (parent[r] != r) {
		r = parent[r];
	}
	int t;
	while (parent[u] != u) {
		t = parent[u];
		parent[u] = r;
		u = t;
	}
	return r;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	dj_init(n);
	while (m--) {
		int x, a, b;
		scanf("%d %d %d", &x, &a, &b);
		int ra = dj_find(a), rb = dj_find(b);
		if (x) {
			printf("%s\n", ra == rb ? "YES" : "NO");
		}
		else {
			parent[rb] = ra;
		}
	}
}