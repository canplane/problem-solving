using namespace std;
#include <cstdio>

int A[10000], N;

void dc(int l, int r)
{
	if (l < r) {
		int e = A[l++];
		int m;
		for (m = l; m < r; m++) {
			if (e < A[m])
				break;
		}
		dc(l, m), dc(m, r);
		printf("%d\n", e);
	}
}

int main()
{
	for (; scanf("%d", &A[N]) == 1; N++);
	dc(0, N);
}