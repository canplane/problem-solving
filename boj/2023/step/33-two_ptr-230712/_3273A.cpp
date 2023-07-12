// 투 포인터는 값이 중복된다면 naive하게 쓸 수 없음.
// 아이디어가 빨리 생각이 안 났다!

using namespace std;
#include <cstdio>
#include <algorithm>

int N;
int A[100000], x;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	scanf("%d", &x);

	sort(A, A + N);
	
	int ans = 0;
	int i = 0, j = N - 1;
	while (i < j) {
		int sum = A[i] + A[j];
		if (sum == x) {
			ans++;
		}
		if (sum <= x) {
			i++;
		}
		else {
			j--;
		}
	}
	printf("%d", ans);
}