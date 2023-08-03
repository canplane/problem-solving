// BOJ 1043 G4 거짓말
// uf나 dfs나 하는 짓 같음. uf도 그래프

using namespace std;
#include <bits/stdc++.h>

int dj[51];
void dj_init(int n)
{
	for (int i = 0; i <= n; i++) {
		dj[i] = i;
	}
}
int dj_find(int x)
{
	while (dj[x] != x) {
		x = dj[x];
	}
	return x;
}
void dj_union(int x, int y)
{
	int rx = dj_find(x), ry = dj_find(y);
	if (rx == 0) {
		dj[ry] = rx;
	}
	else {
		dj[rx] = ry;
	}
}

vector<int> party[50];

int main()
{
	int N, M, n, x;

	scanf("%d %d", &N, &M);
	dj_init(N);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x), dj_union(x, 0);
	}

	for (int i = 0; i < M; i++) {
		int pre_x = -1;
		scanf("%d", &n);
		while (n--) {
			scanf("%d", &x), party[i].push_back(x);
			if (pre_x != -1) {
				dj_union(x, pre_x);
			}
			pre_x = x;
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		bool valid = true;
		for (auto &e : party[i]) {
			if (!dj_find(e)) {
				valid = false;
				break;
			}
		}
		if (valid) {
			ans++;
		}
	}
	printf("%d", ans);
}