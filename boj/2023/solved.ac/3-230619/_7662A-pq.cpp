/*
	틀린 이유: overflow: -(-2^31) = 0
*/

using namespace std;
#include <cstdio>
#include <queue>
#include <map>

void solve()
{
	int k;
	scanf("%d", &k);

	priority_queue<int, vector<int>, less<int>> pq_M;
	priority_queue<int, vector<int>, greater<int>> pq_m;
	map<long, int> m;

	char c;
	int d;
	while (k--) {
		scanf(" %c %d", &c, &d);

		if (c == 'I') {
			pq_M.push(d), pq_m.push(d);
			m[d]++;
		}
		else {
			if (d == 1) {
				if (!pq_M.empty()) {
					m[pq_M.top()]--, pq_M.pop();
				}
			}
			else {
				if (!pq_m.empty()) {
					m[pq_m.top()]--, pq_m.pop();
				}
			}

			while (!pq_M.empty() && m[pq_M.top()] == 0) {
				pq_M.pop();
			}
			while (!pq_m.empty() && m[pq_m.top()] == 0) {
				pq_m.pop();
			}
		}
	}

	if (pq_M.empty())
		printf("EMPTY\n");
	else
		printf("%d %d\n", pq_M.top(), pq_m.top());
}

int main()
{
	int T, k;
	scanf("%d", &T);
	while (T--) {
		solve();
	}
}