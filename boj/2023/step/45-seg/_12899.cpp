using namespace std;
#include <bits/stdc++.h>

int seg[8000001];
void seg_update(int l, int r, int i, int key)
{
	if (l + 1 == r) {
		seg[i]++;
		return;
	}

	int m = (l + r) / 2;
	if (key < m) {
		seg_update(l, m, 2 * i, key);
	}
	else {
		seg_update(m, r, 2 * i + 1, key);
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
	int ret;
	if (sum <= seg[2 * i]) {
		ret = seg_inv_query(l, m, 2 * i, sum);
	}
	else {
		ret = seg_inv_query(m, r, 2 * i + 1, sum - seg[2 * i]);
	}
	seg[i] = seg[2 * i] + seg[2 * i + 1];
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		int cmd, x;
		scanf("%d %d", &cmd, &x);
		if (cmd == 1) {
			seg_update(1, 2000001, 1, x);
		}
		else {
			printf("%d\n", seg_inv_query(1, 2000001, 1, x));
		}
	}
}