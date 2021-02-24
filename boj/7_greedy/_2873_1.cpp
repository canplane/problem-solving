/* 40분 */

#include <cstdio>

int map[1001][1001];

void horiz(int row, int col, char c) {
	for (int y = 1; ; y++) {
		for (int x = 1; x < col; x++)
			putchar(c);
		if (y == row)
			break;
		printf("D");
		c = (c == 'L') ? 'R' : 'L';
	}
}
void vert(int row, int col, char c) {
	for (int x = 1; ; x++) {
		for (int y = 1; y < row; y++)
			putchar(c);
		if (x == col)
			break;
		printf("R");
		c = (c == 'U') ? 'D' : 'U';
	}
}

int main() {
	int R, C;
	scanf("%d %d", &R, &C);
	for (int y = 1; y <= R; y++)
		for (int x = 1; x <= C; x++)
			scanf("%d", &map[y][x]);

	if (R % 2)
		horiz(R, C, 'R');
	else if (C % 2)
		vert(R, C, 'D');
	else {
		int min_cost = map[1][2];
		int min_y = 1, min_x = 2;
		for (int y = 1; y <= R; y++)
			for (int x = y % 2 + 1; x <= C; x += 2)
				if (map[y][x] < min_cost)
					min_cost = map[y][x], min_y = y, min_x = x;

		int y = 1;
		for (; y < 2 * ((min_y - 1) / 2) + 1; y += 2)
			horiz(2, C, 'R'), printf("D");

		int x = 1;
		for (; x < 2 * ((min_x - 1) / 2) + 1; x += 2)
			vert(2, 2, 'D'), printf("R");
		printf((x + 1 == min_x) ? "DR" : "RD"), x += 2;
		for (; x < C; x += 2)
			printf("R"), vert(2, 2, 'U');
		y += 2;
        
		for (; y < R; y += 2)
			printf("D"), horiz(2, C, 'L');
	}
}