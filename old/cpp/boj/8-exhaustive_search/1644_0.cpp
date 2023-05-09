/* 최적화하려고 복잡하게 꼬았는데, 오히려 시간도 용량도 더 크게 잡아먹는다. 
 * 아마 l = eratos[l] 연산이 l++보다 비싸서 그런 것 아닐까.
 */

#include <cstdio>

int eratos[4000001], N;

int main() {
	scanf("%d", &N);

	int last = 0;
	for (int i = 2; i <= N; i++)
		if (!eratos[i]) {
			eratos[last] = i, last = i;
			for (int j = 2 * i; j <= N; j += i)
				eratos[j] = -1;
		}

	int ans = 0, sum = 0, l = 2, r = 2;
	while (true) {
		if (sum == N)
			ans++;
		if (sum >= N)
			sum -= l, l = eratos[l];
		else if (r == 0)
			break;
		else
			sum += r, r = eratos[r];
	}
	printf("%d", ans);
}