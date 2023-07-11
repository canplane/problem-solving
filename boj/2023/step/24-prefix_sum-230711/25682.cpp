// [9 mins]

using namespace std;
#include <cstdio>
#include <algorithm>

int N, M, K;
int S[2001][2001];

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	
	char c;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= M; x++) {
			scanf(" %c", &c);
			S[y][x] = (c == "WB"[(y + x) % 2]) + (S[y - 1][x] + S[y][x - 1] - S[y - 1][x - 1]);
		}
	}
	int ans = K * K, k;
	for (int y = K; y <= N; y++) {
		for (int x = K; x <= M; x++) {
			k = S[y][x] - S[y - K][x] - S[y][x - K] + S[y - K][x - K];
			k = min(k, K * K - k);
			ans = min(ans, k);
		}
	}
	printf("%d", ans);
}