#include <bits/stdc++.h>

int dj[1001];
void dj_init(int n)
{
	for (int i = 1; i <= n; i++)
		dj[i] = i;
}
int dj_find(int u)
{
	while (dj[u] != u)	u = dj[u];
	return u;
}
bool dj_union(int u, int v)
{
	int ru = dj_find(u), rv = dj_find(v);
	dj[rv] = ru;
	return ru != rv;
}

int N, X[1001], Y[1001];
std::priority_queue<std::tuple<double, int, int>> pq;

int main()
{
	int M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++)
		scanf("%d %d", &X[i], &Y[i]);

	dj_init(N);
	while (M--)
		scanf("%d %d", &i, &j), dj_union(i, j);
	
	for (i = 1; i <= N; i++)
		for (j = i + 1; j <= N; j++)
			if (dj_find(i) != dj_find(j))
				pq.push({ -sqrt(pow(X[j] - X[i], 2) + pow(Y[j] - Y[i], 2)), i, j });

	double ans = 0;
	while (!pq.empty()) {
		auto [cost, i, j] = pq.top(); pq.pop();
		if (dj_union(i, j))
			ans += -cost;
	}
	printf("%.2lf", ans);
}