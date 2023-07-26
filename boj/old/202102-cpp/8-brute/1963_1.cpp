#include <cstdio>
#include <cmath>
#include <queue>

bool eratos[10001];

void bfs(int A, int B) {
	std::queue<int> q;
	bool visited[10001] = {};

	int ans = 0, seg = 1;
	q.push(A);
	while (!q.empty()) {
		int X, next_seg = 0;
		while (seg--) {
			X = q.front(), q.pop();
			visited[X] = true;

			if (X == B) {
				printf("%d\n", ans);
				return;
			}
			for (int w = 1; w <= 1000; w *= 10) {
				for (int i = (w == 1000); i < 10; i++) {
					int Y = (X - ((X / w) % 10) * w) + i * w;
					if (!eratos[Y] && !visited[Y])
						q.push(Y), next_seg++;
				}
			}
		}
		ans++, seg = next_seg;
	}
	printf("Impossible\n");
}

int main() {
	for (int i = 2; i < 5000; i++) {
		if (eratos[i])
			continue;
		for (int j = 2 * i; j < 10000; j += i)
			eratos[j] = true;
	}

	int T, A, B;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &A, &B);
		bfs(A, B);
	}
}