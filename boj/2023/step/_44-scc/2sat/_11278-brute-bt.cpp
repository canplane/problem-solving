using namespace std;
#include <bits/stdc++.h>

#define SZ 20

int N, M;
vector<pair<int, int>> cnf;

int val[SZ + 1];
bool check()
{
	bool valid = true;
	for (auto [i, j] : cnf) {
		valid &= (i > 0 ? val[i] : !val[-i]) | (j > 0 ? val[j] : !val[-j]);
	}
	return valid;
}
bool bt(int n_i)
{
	if (check())	return true;
	for (int i = n_i; i <= N; i++) {
		val[i] = true;
		if (bt(i + 1))	return true;
		val[i] = false;
	}
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);

	cnf.resize(M);
	for (int k = 0; k < M; k++) {
		int i, j;
		scanf("%d %d", &i, &j);
		cnf[k] = { i, j };
	}

	int sat = bt(1);
	printf("%d\n", sat);
	if (sat) {
		for (int k = 1; k <= N; k++) {
			printf("%d ", val[k]);
		}
	}
}