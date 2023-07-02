// 2048
// 오래 걸림 (구현이 까다롭다.)

using namespace std;
#include <cstdio>
#include <algorithm>
#include <cstring>

int N;
int A[20][20];

void f(int dir)
{
	int k, t;
	switch (dir) {
	case 0:
		for (int y = 0; y < N; y++) {
			k = 0;
			for (int x = 0; x < N; x++) {
				if ((t = A[y][x])) {
					A[y][x] = 0, A[y][k++] = t;
				}
			}
		}
		break;
	case 1:
		for (int x = 0; x < N; x++) {
			k = 0;
			for (int y = 0; y < N; y++) {
				if ((t = A[y][x])) {
					A[y][x] = 0, A[k++][x] = t;
				}
			}
		}
		break;
	case 2:
		for (int x = 0; x < N; x++) {
			k = N - 1;
			for (int y = N - 1; y >= 0; y--) {
				if ((t = A[y][x])) {
					A[y][x] = 0, A[k--][x] = t;
				}
			}
		}
		break;
	case 3:
		for (int y = 0; y < N; y++) {
			k = N - 1;
			for (int x = N - 1; x >= 0; x--) {
				if ((t = A[y][x])) {
					A[y][x] = 0, A[y][k--] = t;
				}
			}
		}
		break;
	}

}
void g(int dir)
{
	switch (dir) {
	case 0:
		for (int y = 0; y < N; y++) {
			for (int x = 0; x + 1 < N; ) {
				if (A[y][x] == A[y][x + 1]) {
					A[y][x] *= 2, A[y][x + 1] = 0;
					x += 2;
				}
				else
					x += 1;
			}
		}
		break;
	case 1:
		for (int x = 0; x < N; x++) {
			for (int y = 0; y + 1 < N; ) {
				if (A[y][x] == A[y + 1][x]) {
					A[y][x] *= 2, A[y + 1][x] = 0;
					y += 2;
				}
				else
					y += 1;
			}
		}
		break;
	case 2:
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y - 1 >= 0; ) {
				if (A[y][x] == A[y - 1][x]) {
					A[y][x] *= 2, A[y - 1][x] = 0;
					y -= 2;
				}
				else
					y -= 1;
			}
		}
		break;
	case 3:
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x - 1 >= 0; ) {
				if (A[y][x] == A[y][x - 1]) {
					A[y][x] *= 2, A[y][x - 1] = 0;
					x -= 2;
				}
				else
					x -= 1;
			}
		}
		break;
	}
}

int dfs(int d)
{
	int ret = 0;
	if (d == 5) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				ret = max(ret, A[y][x]);
	}
	else {
		int B[20][20];
		memcpy(B, A, sizeof(A));
		
		for (int i = 0; i < 4; i++) {
			f(i), g(i), f(i);
			ret = max(ret, dfs(d + 1));
			memcpy(A, B, sizeof(A));
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &A[y][x]);
		}
	}
	
	printf("%d", dfs(0));
}