// [> 60 mins] 아이디어 생각하는 게 어려웠다. (컨닝은 안 함)
// 누적 합을 한 방식으로만 쓰는 게 아님을 깨달음.

#include <cstdio>

int N, M;
int S[1000001];
long cnt[1000];

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &S[i]);
		S[i] = (S[i] + S[i - 1]) % M;
	}
	
	long ans = 0;
	cnt[0] = 1;
	for (int i = 1; i <= N; i++) {
		ans += cnt[S[i]];
		cnt[S[i]]++;
	}
	printf("%ld", ans);
}