using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[100000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	sort(A, A + N);
	
	int x = A[0], y = A[N - 1];
	int i = 0, j = N - 1;
	while (i < j) {
		int sum = A[i] + A[j];
		if (abs(sum) < abs(x + y)) {
			x = A[i], y = A[j];
		}
		if (sum <= 0) {
			i++;
		}
		else {
			j--;
		}
	}
	printf("%d %d", x, y);
}