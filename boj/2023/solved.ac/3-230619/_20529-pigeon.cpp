using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>

int dist(int a, int b)
{
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		ret += (a & (1 << i)) != (b & (1 << i));
	}
	return ret;
}

int A[16], comb[3];
int combi(int n_i, int r_i)
{
	int ret;
	if (r_i == 3) {
		ret = 0;
		for (int i = 0; i < 3; i++) {
			ret += dist(comb[i], comb[(i + 1) % 3]);
		}
	}
	else {
		ret = 4 * 3;
		for (int i = n_i; i < 16; i++) {
			if (A[i] > 0) {
				A[i]--;
				comb[r_i] = i, ret = min(ret, combi(i, r_i + 1));
				A[i]++;
			}
		}
	}
	return ret;
}

char s[5], C[5] = "ESTJ";
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int N;
		scanf("%d", &N);

		memset(A, 0, sizeof(A));
		for (int i = 0; i < N; i++) {
			scanf("%s", s);
			int k = 0;
			for (int i = 0; i < 4; i++) {
				k += (s[i] == C[i]) << i;
			}
			A[k]++;
		}
		// pigeonhole (비둘기집의 원리)
		printf("%d\n", N > 32 ? 0 : combi(0, 0));
	}
}