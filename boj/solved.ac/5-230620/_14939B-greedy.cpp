#include <bits/stdc++.h>
#define NEG(x) ((x) = !(x))

bool A[12][12], B[12][12];
void toggle(int y, int x)
{
	NEG(B[y - 1][x]), NEG(B[y][x - 1]), NEG(B[y][x]), NEG(B[y][x + 1]), NEG(B[y + 1][x]);
}

int ans = INT_MAX;
void f(int bit)
{
	int cnt = 0;
	memcpy(B, A, sizeof(B));
	for (int x = 1; x <= 10; x++)
		if (bit & (1 << x))
			++cnt, toggle(1, x);
	for (int y = 2; y <= 10; y++)
		for (int x = 1; x <= 10; x++)
			if (B[y - 1][x])
				++cnt, toggle(y, x);
	for (int x = 1; x <= 10; x++)
		if (B[10][x])
			return;
	ans = std::min(ans, cnt);
}
void bt(int x0, int bit)
{
	f(bit);
	for (int x = x0; x <= 10; x++)
		bt(x + 1, bit | (1 << x));
}
int main()
{
	char c;
	for (int y = 1; y <= 10; y++)
		for (int x = 1; x <= 10; x++)
			scanf(" %c", &c), A[y][x] = (c == 'O');
	bt(1, 0);
	printf("%d", ans == INT_MAX ? -1 : ans);
}