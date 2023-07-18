using namespace std;
#include <bits/stdc++.h>

int N, M;
vector<pair<int, int>> cnf;

bool sat;
bool val[21];
void check()
{
	/*for (int i = 1; i <= N; i++) {
		printf("%d ", val[i]);
	}
	printf("\n");*/
	bool ret = true;
	for (auto [i, j] : cnf) {
		ret &= (i > 0 ? val[i] : !val[-i]) | (j > 0 ? val[j] : !val[-j]);
	}
	if (ret) {
		sat = true;
	}
}
void bt(int n_i)
{
	check();
	for (int i = n_i; i <= N; i++) {
		val[i] = true;
		bt(i + 1);
		val[i] = false;
	}
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

	sat = false;
	bt(1);
	printf("%d", sat);
}
