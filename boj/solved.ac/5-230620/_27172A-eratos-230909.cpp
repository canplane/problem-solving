// BOJ 27172 G5 수 나누기 게임
// 발상 전혀 못 떠올림.
// 풀이 설명: https://velog.io/@phraqe/boj27172
// 에라토스테네스의 체(Eratosthenes' Sieve)의 시간 복잡도: O(N log(log N))

using namespace std;
#include <bits/stdc++.h>

int N;
int P[1000001];
int S[100001];

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		P[x] = i;
	}

	for (int x = 1; x <= 1000000; x++) {
		if (P[x]) {
			for (int y = 2 * x; y <= 1000000; y += x) {
				if (P[y]) {
					S[P[x]]++, S[P[y]]--;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		printf("%d ", S[i]);
	}
}