// redirect to 15486 (N이 1500000로 커진 것만 다른 문제 -> 이건 수가 적어서 bt로 풀 수 있는 것)
// 이건 사실 DP로 짜는 게 좋은 문제! (백트래킹 DP 아님. 뒤부터 채우는 DP)
// 무조건적 백트래킹 선호는 지양하자.

using namespace std;
#include <bits/stdc++.h>

int N;
int T[16], P[16];

int bt(int n_i)
{
	int ret = 0;
	for (int i = n_i; i <= N; i++) {
		if (i + T[i] <= N + 1) {	// N 아니라 N + 1. 생각 잘 하자
			ret = max(ret, P[i] + bt(i + T[i]));
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}
	printf("%d", bt(1));
}