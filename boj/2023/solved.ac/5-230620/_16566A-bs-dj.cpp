// 유니언 파인드를 이렇게도 쓸 수 있다!

using namespace std;
#include <bits/stdc++.h>

int N, M, K;
int A[4000000];

int dj[4000001];
void dj_init(int n)
{
	for (int v = 1; v <= n; v++)
		dj[v] = v;
}
int dj_find(int u)
{
	int r = u, t;
	while (r != dj[r])
		r = dj[r];
	while (u != dj[u])
		t = dj[u], dj[u] = r, u = t;
	return r;
}
void dj_union(int to, int from)
{
	int r_to = dj_find(to), r_from = dj_find(from);
	dj[r_from] = r_to;
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < M; i++)
		scanf("%d", &A[i]);
	sort(A, A + M);

	dj_init(N);
	for (int i = 0; i < K; i++) {
		int x;
		scanf("%d", &x);
		int v = dj_find(*upper_bound(A, A + M, x));
		printf("%d\n", v);
		dj_union(v + 1, v);
	}
}