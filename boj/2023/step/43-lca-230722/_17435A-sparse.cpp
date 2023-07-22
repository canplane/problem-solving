// sparse table (희소 배열)
// f_i(f_j(x)) = f_(i + j)(x)

using namespace std;
#include <cstdio>

#define MAX_M 200000
#define MAX_N 500000
#define MAX_LOG_N 18	// floor(log_2 MAX_N)

int M;
int sparse[MAX_M + 1][MAX_LOG_N + 1];	// sparse[x][i] = f_(2^i)(x);

int main()
{
	scanf("%d", &M);
	for (int x = 1; x <= M; x++) {
		scanf("%d", &sparse[x][0]);
	}
	for (int i = 1; i <= MAX_LOG_N; i++) {
		for (int x = 1; x <= M; x++) {
			// f_(2^(i + 1)) = f_(2^i)(f_(2^i)(x))
			sparse[x][i] = sparse[sparse[x][i - 1]][i - 1];
		}
	}

	int Q;
	scanf("%d", &Q);
	while (Q--) {
		int n, x;
		scanf("%d %d", &n, &x);
		for (int i = 0; i <= MAX_LOG_N; i++) {
			if (n & (1 << i)) {
				x = sparse[x][i];
			}
		}
		printf("%d\n", x);
	}
}