/*
	오래 걸린 이유: disjoint set 익숙지 않음
*/

using namespace std;
#include <cstdio>
#include <cstring>

int A[1001][1001];
int N;

int parent[1001];
void dj_init(int n)
{
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}
int dj_find(int x)
{
	int r = x;
	while (parent[r] != r)
		r = parent[r];
	
	while (parent[x] != x) {
		int t = x;
		x = parent[x];
		parent[t] = r;
	}
	return r;
}
void dj_union(int x, int y)
{
	int rx = dj_find(x), ry = dj_find(y);
	parent[ry] = x;
}
int dj_size(int n)
{
	bool is_root[n + 1];
	memset(is_root, 0, sizeof(is_root));
	for (int i = 1; i <= n; i++)
		is_root[dj_find(i)] = true;
	
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret += is_root[i];
	return ret;
}

int main()
{
	scanf("%d", &N);

	dj_init(N);
	for (int i = 1; i <= N; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1 += 500, y1 += 500, x2 += 500, y2 += 500;
		
		for (int y = y1; y <= y2; y++) {
			if (A[y][x1])
				dj_union(i, A[y][x1]);
			if (A[y][x2])
				dj_union(i, A[y][x2]);
			A[y][x1] = A[y][x2] = i;
		}
		for (int x = x1; x <= x2; x++) {
			if (A[y1][x])
				dj_union(i, A[y1][x]);
			if (A[y2][x])
				dj_union(i, A[y2][x]);
			A[y1][x] = A[y2][x] = i;
		}
	}
	printf("%d", dj_size(N) - !!A[500][500]);
}