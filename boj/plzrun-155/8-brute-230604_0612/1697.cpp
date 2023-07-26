/* [5 -> 17]
5, 6, 7, 8, 16, 17
5, 4, 8, 16, 17
*/

using namespace std;
#include <cstdio>
#include <deque>

int N, K;
int dist[200001];
bool visit[200001];

int bfs(int N, int K)
{
	deque<int> q;
	dist[N] = 0;
	visit[N] = true, q.push_back(N);
	while (!q.empty()) {
		int x = q.front(); q.pop_front();
		int d = dist[x] + 1;
		if (x - 1 >= 0 && !visit[x - 1]) {
			dist[x - 1] = d;
			visit[x - 1] = true, q.push_back(x - 1);
		}
		if (x + 1 <= 200000 && !visit[x + 1]) {
			dist[x + 1] = d;
			visit[x + 1] = true, q.push_back(x + 1);
		}
		if (2 * x <= 200000 && !visit[2 * x]) {
			dist[2 * x] = d;
			visit[2 * x] = true, q.push_back(2 * x);
		}
	}
	return dist[K];
}

int main()
{
	scanf("%d %d", &N, &K);
	printf("%d", bfs(N, K));
}