using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int cost[10][10];
int path[11];

#define INF -1L
int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &cost[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		path[i] = i;
	}
	path[N] = 0;

	unsigned long ans = INF;
	do {
		bool valid = true;
		unsigned long dist = 0;
		for (int i = 1; i <= N; i++) {
			int tmp = cost[path[i - 1]][path[i]];
			if (tmp == 0) {
				valid = false;
				break;
			}
			dist += tmp;
		}
		if (valid)
			ans = min(ans, dist);
	} while (next_permutation(path + 1, path + N));
	printf("%lu", ans);
}