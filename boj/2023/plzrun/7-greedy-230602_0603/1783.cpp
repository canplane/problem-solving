using namespace std;
#include <cstdio>
#include <algorithm>

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	long ans;
	if (N == 1) {
		ans = 1;
	}
	else if (N == 2) {
		ans = min(4, (M + 1) / 2);
	}
	else {
		if (M > 4)
			ans = max(4, M - 2);
		else
			ans = M; 
	}
	printf("%ld", ans);
}