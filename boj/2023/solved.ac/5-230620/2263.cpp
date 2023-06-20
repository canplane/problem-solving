using namespace std;
#include <cstdio>

int n;
int I[100001], P[100001];

void dc(int l, int lP, int d)
{
	if (d > 0) {
		int e = P[(lP + d) - 1];
		int dl;
		for (dl = 0; l + dl < l + d; dl++) {
			if (I[l + dl] == e) {
				break;
			}
		}
		printf("%d ", e);
		dc(l, lP, dl), dc((l + dl) + 1, lP + dl, d - dl - 1);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &I[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &P[i]);
	}

	dc(1, 1, n);
}