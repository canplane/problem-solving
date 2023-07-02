using namespace std;
#include <cstdio>

int parent[500001];
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
bool dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	if (ru == rv) {
		return true;
	}
	parent[rv] = ru;
	return false;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	dj_init(n);
	
	int i;
	for (i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		if (dj_union(u, v)) {
			printf("%d", i);
			break;
		}
	}
	if (i == m + 1) {
		printf("0");
	}
}