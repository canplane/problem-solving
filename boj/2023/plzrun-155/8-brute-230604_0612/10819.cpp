using namespace std;
#include <cstdio>
#include <algorithm>

int A[8], N;

int permut(int r_i)
{
	int ret = 0;
	if (r_i == N) {
		for (int i = 1; i < N; i++)
			ret += abs(A[i - 1] - A[i]);
		return ret;
	}
	for (int i = r_i; i < N; i++) {
		swap(A[r_i], A[i]);
		ret = max(ret, permut(r_i + 1));
		swap(A[r_i], A[i]);
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