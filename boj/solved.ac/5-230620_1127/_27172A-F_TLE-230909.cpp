// BOJ 27172 G5 수 나누기 게임
// 당연히 Failed: O(N^2)

using namespace std;
#include <bits/stdc++.h>

int N;
int A[100000];
int S[100000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (!(A[i] % A[j])) {
				S[i]--, S[j]++;
			}
			else if (!(A[j] % A[i])) {
				S[j]--, S[i]++;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", S[i]);
	}
}