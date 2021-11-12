#include <stdio.h>
#include <stdbool.h>
#include <string.h>
int tc, a, b, n;
int q[10001], p[10001], c[10001];  // p: prev, c: 문자 인덱스
bool v[10001];  // v: visited
char s[] = " DSLR";

void enq(int x, int y, int z) { if (!v[x]) { v[x] = true; q[n++] = x; p[x] = y; c[x] = z; } }
void dfs(int x) {
	if (p[x] >= 0) {
		dfs(p[x]);
		putchar(s[c[x]]);
	}
}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &a, &b);
		n = 0;
		memset(v, 0, sizeof(v));
		enq(a, -1, 0);
		for (int i = 0; !v[b]; ++i) {
			enq((q[i] * 2) % 10000, q[i], 1);
			enq((q[i] + 9999) % 10000, q[i], 2);
			enq(q[i]/1000+(q[i] % 1000)*10, q[i], 3);
			enq(q[i]/10+(q[i]%10)*1000, q[i], 4);
		}
		dfs(b);
		putchar('\n');
	}
	return 0;
}