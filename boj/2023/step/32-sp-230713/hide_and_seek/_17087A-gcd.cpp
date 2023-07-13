// 숨바꼭질 6
// gcd: 왜 멍청하게 이분탐색으로 풀려고 했지...

using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[100002];

int gcd(int a, int b)
{
	int t;
	while (b) {
		t = a, a = b, b = t % b;
	}
	return a;
}

int main()
{
	scanf("%d %d", &N, &A[0]);
	N++;
	for (int i = 1; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);

	int ans = A[1] - A[0];
	for (int i = 2; i < N; i++) {
		ans = gcd(ans, A[i] - A[i - 1]);
	}
	printf("%d", ans);
}