// 4 ms

#include <cstdio>

#define MAX_N 123456

bool np[MAX_N * 2 + 1];
void eratos()
{
	np[0] = np[1] = true;
	for (int i = 2; i <= MAX_N; i++) {
		if (np[i]) {
			continue;
		}
		for (int j = 2 * i; j <= MAX_N * 2; j += i) {
			np[j] = true;
		}
	}
}

int main()
{
	eratos();

	while (true) {
		int N;
		scanf("%d", &N);
		if (N == 0) {
			break;
		}

		int cnt = 0;
		for (int x = N + 1; x <= 2 * N; x++) {
			cnt += !np[x];
		}
		printf("%d\n", cnt);
	}
}