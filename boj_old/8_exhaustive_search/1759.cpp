/* 문제 좀 잘 읽어라... a, e, i, o, u 어디에 빼 먹었노 */

#include <cstdio>
#include <algorithm>

char alpha[15], key[16];
int L, C;

void dfs(int l, int c, int vow) {
	if (l == L) {
		if (vow >= 1 && L - vow >= 2)
			printf("%s\n", key);
		return;
	}
	for (; C - c >= L - l; c++) {
		key[l] = alpha[c];

		int nvow = vow;
		switch (key[l])
		case 'a': case 'e': case 'i': case 'o': case 'u':
			nvow++;
		dfs(l + 1, c + 1, nvow);
	}
}

int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++)
		scanf(" %c", &alpha[i]);
	std::sort(alpha, alpha + C);
	dfs(0, 0, 0);
}