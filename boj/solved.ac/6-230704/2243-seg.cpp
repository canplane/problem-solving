using namespace std;
#include <cstdio>
#include <algorithm>

#define N 1000000

int seg[4 * N + 1];
void seg_update(int l, int r, int i, int key, int val)
{
	if (l + 1 == r) {
		seg[i] += val;
		return;
	}
	int m = (l + r) / 2;
	if (key < m) {
		seg_update(l, m, 2 * i, key, val);
	}
	else {
		seg_update(m, r, 2 * i + 1, key, val);
	}
	seg[i] = seg[2 * i] + seg[2 * i + 1];
}
int seg_inv_query(int l, int r, int i, int sum)
{
	if (l + 1 == r) {
		seg[i]--;
		return l;
	}

	int m = (l + r) / 2;
	int key;
	if (sum <= seg[2 * i]) {
		key = seg_inv_query(l, m, 2 * i, sum);
	}
	else {
		key = seg_inv_query(m, r, 2 * i + 1, sum - seg[2 * i]);
	}
	seg[i] = seg[2 * i] + seg[2 * i + 1];
	return key;
}

int main()
{
	int M;
	scanf("%d", &M);

	while (M--) {
		int a, b, c;
		scanf("%d", &a);
		if (a == 1) {
			scanf("%d", &b);
			printf("%d\n", 1 + seg_inv_query(0, N, 1, b));
		}
		else {
			scanf("%d %d", &b, &c);
			seg_update(0, N, 1, b - 1, c);
		}
	}
}