// 숨바꼭질 1

using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

bool visit[200001];
int main()
{
	int N, K;
	scanf("%d %d", &N, &K);

	deque<pair<int, int>> q;
	visit[N] = true, q.push_back({ N, 0 });
	while (!q.empty()) {
		auto [u, d] = q.front(); q.pop_front();
		
		if (u == K) {
			printf("%d", d);
			break;
		}

		int v;
		if ((v = 2 * u) <= 200000 && !visit[v]) {
			visit[v] = true, q.push_back({ v, d + 1 });
		}
		if ((v = u + 1) <= 200000 && !visit[v]) {
			visit[v] = true, q.push_back({ v, d + 1 });
		}
		if ((v = u - 1) >= 0 && !visit[v]) {
            visit[v] = true, q.push_back({ v, d + 1 });
        }	
	}
}