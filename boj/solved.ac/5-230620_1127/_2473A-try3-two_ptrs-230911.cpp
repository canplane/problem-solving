// BOJ 2473 G3 세 용액
// 3rd trial: O(N^2): 1개 naive하게 잡고, 2개 투 포인터: 중복성 검사 때문에 비효율적
// 이분 탐색보다 투 포인터가 빠름

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

	long B[3] = { A[0], A[1], A[2] }, s_m = A[0] + A[1] + A[2];
	for (int k = 0; k < N; k++) {
		int i = 0, j = N - 1;
		while (i < j) {
			if (i == k) {
				i++;
				continue;
			}
			if (j == k) {
				j--;
				continue;
			}

			long s = A[i] + A[j] + A[k];
			if (abs(s) < abs(s_m)) {
				B[0] = A[i], B[1] = A[j], B[2] = A[k], s_m = s;
			}

			if (s < 0) {
				i++;
			}
			else if (s > 0) {
				j--;
			}
			else {
				break;
			}
		}
	}
	sort(B, B + 3);
	printf("%ld %ld %ld", B[0], B[1], B[2]);
}