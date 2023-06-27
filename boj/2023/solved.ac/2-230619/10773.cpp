#include <cstdio>

int A[100000], sz;

int main()
{
	int K;
	scanf("%d", &K);
	while (K--) {
		int x;
		scanf("%d", &x);
		if (x == 0)
			sz--;
		else
			A[sz++] = x;
	}

	int cnt = 0;
	for (int i = 0; i < sz; i++)
		cnt += A[i];
	printf("%d", cnt);
}