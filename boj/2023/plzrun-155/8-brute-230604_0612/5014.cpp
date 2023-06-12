using namespace std;
#include <cstdio>
#include <queue>

int F, S, G, U, D;
int d[1000001];

int bfs()
{
	queue<int> q;
	d[S] = 1, q.push(S);
	while (q.size()) {
		int v = q.front(); q.pop();
		if (v == G)
			return d[G] - 1;
		int w;
		if ((w = v + U) <= F && !d[w])
			d[w] = d[v] + 1, q.push(w);
		if ((w = v - D) >= 1 && !d[w])
			d[w] = d[v] + 1, q.push(w);
	}
	return -1;
}

int main()
{
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	int ans = bfs();
	printf(ans == -1 ? "use the stairs" : "%d", ans);
}