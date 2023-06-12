using namespace std;
#include <cstdio>
#include <algorithm>

#define INF 0x7fffffff

int N, S;
int A[100000];

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);

	int i = 0, j = 0;
	int sum = 0;
	int ans = INF;
	while (j <= N) {
		if (sum >= S)
			ans = min(ans, j - i);
		if (sum < S)
			sum += A[j++];
		else
			sum -= A[i++];
	}
	printf("%d", ans == INF ? 0 : ans);
}