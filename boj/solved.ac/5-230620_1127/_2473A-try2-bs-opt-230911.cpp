// BOJ 2473 G3 세 용액
// 2nd trial: O(N^2 log N): 2개 naive하게 잡고 1개 이분탐색: 최적화 (중복성 제거)

using namespace std;
#include <bits/stdc++.h>

int N;
long A[5000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%ld", &A[i]);
	}
	sort(A, A + N);

	long B[3] = { A[0], A[1], A[2] };
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int k = lower_bound(A + j + 1, A + N, -(A[i] + A[j])) - A;

			if (k < N && abs(A[i] + A[j] + A[k]) < abs(B[0] + B[1] + B[2])) {
				B[0] = A[i], B[1] = A[j], B[2] = A[k];
			}
			if ((k = k - 1) > j && abs(A[i] + A[j] + A[k]) < abs(B[0] + B[1] + B[2])) {
				B[0] = A[i], B[1] = A[j], B[2] = A[k];
			}
		}
	}
	printf("%ld %ld %ld", B[0], B[1], B[2]);
}