// y = x 대칭 -> x축 대칭 -> y 방향 평행 이동
// (x, y) -> (y, x) -> (y, -x) -> (y, -(x - (M - 1)))

using namespace std;
#include <cstdio>
#include <map>

int N, M;
char A[100][100], B[100][100];
char D[256];
char _D[][2] = {
	{ '.', '.' }, { 'O', 'O' }, { '-', '|' }, { '|', '-' },
	{ '/', '\\' }, { '\\', '/'}, { '^', '<' }, { '<', 'v' },
	{ 'v', '>' }, { '>', '^' }, { 0, 0 }
};

int main()
{
	for (int i = 0; _D[i][0]; i++) {
		D[_D[i][0]] = _D[i][1];
	}

	scanf("%d %d", &N, &M);
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			scanf(" %c", &A[y][x]);
		}
	}
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			B[(M - 1) - x][y] = D[A[y][x]];
		}
	}
	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++) {
			printf("%c", B[y][x]);
		}
		printf("\n");
	}
}