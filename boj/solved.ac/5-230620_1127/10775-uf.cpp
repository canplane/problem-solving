// BOJ 10775 G2 공항

using namespace std;
#include <bits/stdc++.h>

int dj[100001];
void dj_init(int n)
{
	for (int u = 0; u <= n; u++)	dj[u] = u;
}
int dj_find(int u)
{
	int r = u, t;
	while (dj[r] != r)	r = dj[r];
	while (dj[u] != u)	t = dj[u], dj[u] = r, u = t;
	return r;
}
void dj_union(int u, int v)
{
	dj[dj_find(v)] = dj_find(u);
}

int main()
{
	int G, P;
	scanf("%d %d", &G, &P);

	dj_init(G);
	int i, x;
	for (i = 0; i < P; i++) {
		scanf("%d", &x);

		int r = dj_find(x);
		if (!r)	break;
		dj_union(r - 1, r);
	}
	printf("%d", i);
}