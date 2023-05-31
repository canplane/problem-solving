using namespace std;
#include <cstdio>
#include <algorithm>

int N, M;
int A[500000], x;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &x);
		printf("%ld ", upper_bound(A, A + N, x) - lower_bound(A, A + N, x));
	}
}