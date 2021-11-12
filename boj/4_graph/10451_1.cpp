#include <cstdio>

int next[1001];
bool visit[1001];

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);
		for (int v = 1; v <= N; v++) {
			scanf("%d", &next[v]);
			visit[v] = false;
		}

		int ans = 0;
		for (int v = 1; v <= N; v++) {
			if (!visit[v]) {
				++ans;
				do {
					visit[v] = true;
				} while (!visit[v = next[v]]);
			}
		}
		printf("%d\n", ans);
	}
}