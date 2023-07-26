using namespace std;
#include <cstdio>
#include <algorithm>

char A[16];

bool is_valid(char s[])
{
	int v = 0, c = 0;
	for (char *p = s; *p; p++) {
		if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u')
			v += 1;
		else
			c += 1;
	}
	return v >= 1 && c >= 2;
}

char comb[16];
void combi(int n, int n_i, int r, int r_i)
{
	if (r_i == r) {
		if (is_valid(comb))
			printf("%s\n", comb);
		return;
	}
	for (int i = n_i; i < n; i++) {
		comb[r_i] = A[i], combi(n, i + 1, r, r_i + 1);
	}
}

int main()
{
	int L, C;
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++) {
		scanf(" %c", &A[i]);
	}
	sort(A, A + C);

	combi(C, 0, L, 0);
}