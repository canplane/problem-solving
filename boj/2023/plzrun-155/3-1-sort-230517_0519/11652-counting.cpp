using namespace std;
#include <cstdio>
#include <algorithm>

long A[100000];

int main()
{
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%lld", A + i);
	sort(A, A + N);

	long ans = A[0];
	int cnt = 1, cnt_max = 1;
	for (int i = 1; i < N; i++) {
		if (A[i - 1] != A[i])   cnt = 0;
		cnt += 1;

		if (cnt > cnt_max)  ans = A[i], cnt_max = cnt;
	}
	printf("%lld", ans);
}