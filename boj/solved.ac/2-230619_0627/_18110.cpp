using namespace std;
#include <cstdio>
#include <cmath>
#include <algorithm>

int N;
int A[300000];

char buf[300];

int main()
{
	scanf("%d", &N);
	if (N > 0) {
		for (int i = 0; i < N; i++) {
			scanf("%d", &A[i]);
		}
		sort(A, A + N);
		
		int k = (int)round(N * 0.15);
		int cnt = 0;
		for (int i = k; i < N - k; i++) {
			cnt += A[i];
		}
		// printf도 round 오류 있나 봄! 포맷팅으로 라운딩하면 틀림!
		printf("%d", (int)round((double)cnt / (N - 2 * k)));
	}
	else {
		printf("0");
	}
}