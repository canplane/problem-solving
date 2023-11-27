// BOJ 13334 G2 철로

using namespace std;
#include <bits/stdc++.h>

int N;
pair<int, int> A[100000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		if (s > e) {
			swap(s, e);
		}
		A[i] = { e, s };
	}
	sort(A, A + N);

	int d;
	scanf("%d", &d);

	priority_queue<int, vector<int>, greater<>> pq;
	int cnt_max = 0, cnt = 0;

	for (int i = 0; i < N; i++) {
		auto &[e, s] = A[i];

		pq.push(s), cnt += 1;
		while (!pq.empty()) {
			int s1 = pq.top();
			if (e - s1 <= d) {
				break;
			}
			pq.pop(), cnt -= 1;
		}
		cnt_max = max(cnt_max, cnt);
	}
	printf("%d", cnt_max);
}