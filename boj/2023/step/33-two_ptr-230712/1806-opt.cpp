using namespace std;
#include <cstdio>
#include <algorithm>

#define INF ((1L << 31) - 1)

int N;
int A[100000 + 1], S;	// +1 !

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	
	int ans = INF;
	int sum = 0;
	int i = 0, j = 0;
	while (j <= N) {
		if (sum >= S) {
			ans = min(ans, j - i);
			sum -= A[i++];
		}
		else {
			sum += A[j++];
		}
	}
	printf("%d", ans == INF ? 0 : ans);
}