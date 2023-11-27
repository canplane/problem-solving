// BOJ 2467 G5 용액
// 17 mins

using namespace std;
#include <bits/stdc++.h>

int N;
int A[100000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	int l = 0, r = N - 1;
	int k_m = A[l] + A[r], a = A[l], b = A[r];
	while (l < r) {
		int k = A[l] + A[r];
		if (abs(k) < abs(k_m)) {
			k_m = k, a = A[l], b = A[r];
		}
		
		if (k < 0) {
			l++;
		}
		else if (k > 0) {
			r--;
		}
		else {
			break;
		}
	}
	printf("%d %d", a, b);
}