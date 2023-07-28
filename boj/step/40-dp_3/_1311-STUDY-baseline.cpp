using namespace std;
#include <bits/stdc++.h>

int N;
int D[20][20];

bool vis[20];
int bt(int i)
{
	if (i == N) {
		return 0;
	}
	int ret = INT_MAX;
	for (int j = 0; j < N; j++) {
		if (!vis[j]) {
			vis[j] = true;
			ret = min(ret, D[i][j] + bt(i + 1));
			vis[j] = false;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &D[i][j]);
		}
	}
	printf("%d", bt(0));
}