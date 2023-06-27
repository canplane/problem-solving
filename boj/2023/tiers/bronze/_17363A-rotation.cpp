// 난 어려웠는데 남들은 왜 쉽다는진 잘 모르겠음
// y = x 대칭 -> x축 대칭 -> y 방향 평행 이동
// (x, y) -> (y, x) -> (y, -x) -> (y, -(x - (M - 1)))

#include <cstdio>

int N, M;
char A[100][100], B[100][100];

char D[256];

int main()
{
	D['.'] = '.', D['O'] = 'O', D['-'] = '|', D['|'] = '-',
	D['/'] = '\\', D['\\'] = '/', D['^'] = '<', D['<'] = 'v',
	D['v'] = '>', D['>'] = '^';

	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf(" %c", &A[y][x]);
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			B[M - 1 - x][y] = D[A[y][x]];
		}
	}
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			printf("%c", B[y][x]);
		}
		printf("\n");
	}
}