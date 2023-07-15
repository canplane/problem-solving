#include <cstdio>

int dj[201];
void dj_init(int n)
{
	for (int u = 1; u <= n; u++) {
		dj[u] = u;
	}
}
int dj_find(int u)
{
	while (dj[u] != u) {
		u = dj[u];
	}
	return u;
}
void dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	dj[rv] = ru;
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	dj_init(N);

	int x;
	for (int u = 1; u <= N; u++) {
		for (int v = 1; v <= N; v++) {
			scanf("%d", &x);
			if (x == 1) {
				dj_union(u, v);
			}
		}
	}

	bool valid = true;
	scanf("%d", &x);
	int r = dj_find(x);
	for (int i = 1; i < M; i++) {
		scanf("%d", &x);
		if (dj_find(x) != r) {
			valid = false;
			break;
		}
	}
	printf("%s", valid ? "YES" : "NO");
}