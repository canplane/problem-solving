using namespace std;
#include <cstdio>
#include <algorithm>

int A[8], N;

int permut(int idx)
{
	int ret = 0;
	if (idx == N) {
		for (int i = 1; i < N; i++)
			ret += abs(A[i - 1] - A[i]);
		return ret;
	}
	for (int i = idx; i < N; i++) {
		swap(A[idx], A[i]);
		ret = max(ret, permut(idx + 1));
		swap(A[idx], A[i]);
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	int ans = permut(0);
	printf("%d", ans);
}