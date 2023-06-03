/*
1. odd * (.) -> traverse all
2. even * odd -> traverse all
3. even * even -> (2k) * (2l - 1) 꼴 위치 1개 빼기
*/

using namespace std;
#include <cstdio>

int R, C;
int A[1000][1000];

int main()
{
	scanf("%d %d", &R, &C);
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			scanf("%d", &A[y][x]);
		}
	}

	if (R % 2) {
		for (int y = 0; y < R - 1; y += 2) {
			for (int x = 0; x < C - 1; x++)		printf("R");
			printf("D");
			for (int x = C - 2; x >= 0; x--)	printf("L");
			printf("D");
		}
		for (int x = 0; x < C - 1; x++)		printf("R");
	}
	else if (C % 2) {
		for (int x = 0; x < C - 1; x += 2) {
			for (int y = 0; y < R - 1; y++)		printf("D");
			printf("R");
			for (int y = R - 2; y >= 0; y--)	printf("U");
			printf("R");
		}
		for (int y = 0; y < R - 1; y++)		printf("D");
	}
	else {
		int min_y = 0, min_x = 1;
		for (int y = 0; y < R; y++)
			for (int x = (y + 1) % 2; x < C; x += 2)
				if (A[y][x] < A[min_y][min_x])
					min_y = y, min_x = x;
		int R1 = 2 * (min_y / 2);
		int R2 = R1 + 2;

		for (int y = 0; y < R1; y += 2) {
			for (int x = 0; x < C - 1; x++)		printf("R");
			printf("D");
			for (int x = C - 2; x >= 0; x--)	printf("L");
			printf("D");
		}
		for (int x = 0; x < min_x; x++)			printf(x % 2 ? "UR" : "DR");
		for (int x = min_x; x < C - 1; x++)		printf(x % 2 ? "RU" : "RD");
		for (int y = R2; y < R; y += 2) {
			printf("D");
			for (int x = C - 2; x >= 0; x--)	printf("L");
			printf("D");
			for (int x = 0; x < C - 1; x++)		printf("R");
		}
	}
}