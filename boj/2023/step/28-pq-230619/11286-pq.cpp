// BOJ 11286 S1 절댓값 힙

using namespace std;
#include <cstdio>
#include <queue>
#include <utility>

priority_queue<pair<int, bool>> pq;

int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (!pq.empty()) {
				auto [_x, neg] = pq.top(); pq.pop();
				x = -_x;
				if (neg)
					x = -x;
			}
			printf("%d\n", x);
		}
		else {
			bool neg = false;
			if (x < 0)
				x = -x, neg = true;
			pq.push({ -x, neg });
		}
	}
}