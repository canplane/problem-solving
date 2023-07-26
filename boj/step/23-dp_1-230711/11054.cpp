using namespace std;
#include <bits/stdc++.h>

int N;
int A[1000];
int inc[1000], dsc[1000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		inc[i] = 1;
		for (int j = 0; j < i; j++) {
			if (A[j] < A[i]) {
				inc[i] = max(inc[i], inc[j] + 1);
			}
		}
	}
	for (int i = N - 1; i >= 0; i--) {
		dsc[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (A[i] > A[j]) {
				dsc[i] = max(dsc[i], dsc[j] + 1);
			}
		}
	}
	int ans = inc[0] + dsc[0] - 1;
	for (int i = 0; i < N; i++) {
		ans = max(ans, inc[i] + dsc[i] - 1);
	}
	printf("%d", ans);
}