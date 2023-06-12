using namespace std;
#include <cstdio>
#include <algorithm>

int A[8], N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	sort(A, A + N);

	int ans = 0;
	do {
		int ret = 0;
		for (int i = 1; i < N; i++)
			ret += abs(A[i - 1] - A[i]);
		ans = max(ans, ret);
	} while (next_permutation(A, A + N));
	printf("%d", ans);
}