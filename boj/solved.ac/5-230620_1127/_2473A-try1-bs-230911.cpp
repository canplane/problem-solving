// BOJ 2473 G3 세 용액
// 1st trial: O(N^2 log N): 2개 naive하게 잡고 1개 이분탐색: 중복성 검사 때문에 비효율적

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

	int I[3] = { 0, 1, 2 };
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			long ab = A[i] + A[j];
			int k_l = lower_bound(A, A + N, -ab) - A, k_r = upper_bound(A, A + N, -ab) - A;

			for (int k = k_l; k < k_r; k++) {
				if (k != i && k != j) {
					if (abs(ab + A[k]) < abs(A[I[0]] + A[I[1]] + A[I[2]])) {
						I[0] = i, I[1] = j, I[2] = k;
					}
					break;
				}
			}

			for (int k = k_l - 1; k >= 0; k--) {
				if (k != i && k != j) {
					if (abs(ab + A[k]) < abs(A[I[0]] + A[I[1]] + A[I[2]])) {
						I[0] = i, I[1] = j, I[2] = k;
					}
					break;
				}
			}
			for (int k = k_r; k < N; k++) {
				if (k != i && k != j) {
					if (abs(ab + A[k]) < abs(A[I[0]] + A[I[1]] + A[I[2]])) {
						I[0] = i, I[1] = j, I[2] = k;
					}
					break;
				}
			}
		}
	}
	long S[3] = { A[I[0]], A[I[1]], A[I[2]] };
	sort(S, S + 3);
	printf("%ld %ld %ld", S[0], S[1], S[2]);
}