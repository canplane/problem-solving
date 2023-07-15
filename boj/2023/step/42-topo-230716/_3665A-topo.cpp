// 위상 정렬 말고 더 빠른 방식이 있는데 잘 이해가 안 됨. 정렬 기반인 듯?

using namespace std;
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <cstring>

int N;
int A[500];

bool nxt[501][501];
int indeg[501];

void sol()
{
	vector<int> adj[501];
	memset(nxt, 0, sizeof(nxt));
	memset(indeg, 0, sizeof(indeg));

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		for (int j = 0; j < i; j++) {
			nxt[A[j]][A[i]] = true;
		}
	}

	int M;
	scanf("%d", &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		swap(nxt[a][b], nxt[b][a]);
	}
	for (int u = 1; u < 501; u++) {
		for (int v = 1; v < 501; v++) {
			if (nxt[u][v]) {
				adj[u].push_back(v), indeg[v]++;
			}
		}
	}

	vector<int> ans;
	deque<int> q;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (indeg[A[i]] == 0) {
			q.push_back(A[i]), cnt++;
		}
	}
	if (cnt > 1) {
		printf("?"); return;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop_front();
		ans.push_back(u);

		int cnt = 0;
		for (int v : adj[u]) {
			if (--indeg[v] == 0) {
				q.push_back(v), cnt++;
			}
		}
		if (cnt > 1) {
			printf("?"); return;
		}
	}
	if (ans.size() == N) {	// 위상정렬에서 사이클에 포함된 노드는 큐에 못 들어간다.
		for (int u : ans) {
			printf("%d ", u);
		}
	}
	else {
		printf("IMPOSSIBLE");
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		sol();
		printf("\n");
	}
}