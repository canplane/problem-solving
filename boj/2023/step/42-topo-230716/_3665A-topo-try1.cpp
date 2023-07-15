using namespace std;
#include <cstdio>
#include <cstring>
#include <deque>
#include <vector>
#include <algorithm>

bool adj[501][501];
int indeg[501];

void sol()
{
	memset(adj, 0, sizeof(adj)), memset(indeg, 0, sizeof(indeg));

	vector<int> A;
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		for (int y : A) {
			adj[y][x] = true, ++indeg[x];
		}
		A.push_back(x);
	}

	int M;
	scanf("%d", &M);
	while (M--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (!adj[x][y]) {
			swap(x, y);
		}
		adj[x][y] = false, --indeg[y];
		adj[y][x] = true, ++indeg[x];
	}
	
	int candi = -1;
	for (int x = 1; x <= N; x++) {
		if (!indeg[x]) {
			if (candi != -1) {
				printf("?\n"); return;
			}
			candi = x;
		}
	}
	if (candi == -1) {
		printf("IMPOSSIBLE\n"); return;
	}

	vector<int> ans;
	deque<int> q;
	q.push_back(candi);
	while (!q.empty()) {
		int x = q.front(); q.pop_front();
		ans.push_back(x);

		int candi = -1, indeg_max = 0;
		for (int y = 1; y <= N; y++) {
			if (adj[x][y] && !(--indeg[y])) {
				if (candi != -1) {
					printf("?\n"); return;
				}
				candi = y;
			}
			indeg_max = max(indeg_max, indeg[y]);
		}
		if (candi == -1) {
			if (indeg_max) {
				printf("IMPOSSIBLE\n"); return;
			}
		}
		else {
			q.push_back(candi);
		}
	}
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
	}
}