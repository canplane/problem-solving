using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x3fff'ffff

int N;
int D[100][100];

int main()
{
	int M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			D[i][j] = INF;
		}
	}
	for (int i = 0; i < N; i++) {
		D[i][i] = 0;
	}
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		D[a - 1][b - 1] = D[b - 1][a - 1] = 1;
	}
	
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	int ans_cnt = INF, ans;
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			cnt += D[i][j];
		}
		if (cnt < ans_cnt) {
			ans_cnt = cnt, ans = i;
		}
	}
	printf("%d", ans + 1);
}