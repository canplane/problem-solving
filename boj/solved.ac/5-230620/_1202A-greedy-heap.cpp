// BOJ 1202 G2 보석 도둑
// 이분탐색보다 이 풀이가 정석인데 생각 못함. 그리디!! (작은 배낭부터해서 가능한 보석들을 가격에 대한 최대힙에 모두 쑤셔 넣고 하나 빼기)
// https://please-amend.tistory.com/entry/백준-1202번-보석-도둑-Ccpp-풀이-그림-설명

using namespace std;
#include <bits/stdc++.h>

int N, K;
pair<int, int> A[300000];
int C[300000];

int main()
{
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		int m, v;
		scanf("%d %d", &m, &v);
		A[i] = { m, v };
	}
	for (int i = 0; i < K; i++)
		scanf("%d", &C[i]);

	sort(A, A + N), sort(C, C + K);

	long ans = 0;
	priority_queue<int> pq;
	int j = 0;
	for (int i = 0; i < K; i++) {
		while (j < N) {
			auto [m, v] = A[j];
			if (m > C[i])
				break;
			j += 1, pq.push(v);
		}
		if (!pq.empty())
			ans += pq.top(), pq.pop();
	}
	printf("%ld", ans);
}