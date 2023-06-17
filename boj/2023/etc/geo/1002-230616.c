#include <stdio.h>
#include <math.h>

int solve()
{
	int x1, y1, r1, x2, y2, r2;
	scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);

	// r1가 r2 이상이도록 보장하자
	if (r1 < r2) {
		int temp;
		temp = r1; r1 = r2; r2 = temp;  // swap
	}

	double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (d == 0) { // P1 == P2
		if (r1 == r2) {
			if (r1 == 0)
				return 1;
			else
				return -1;
		}
		else {
			return 0;
		}
	}
	else {  // P1 != P2
		if (d < r1 - r2) {
			return 0;
		}
		else if (d == r1 - r2) {
			return 1;
		}
		else if (r1 - r2 < d && d < r1 + r2) {
			if (r1 < r2 + d && r2 < r1 + d) {
				return 2;
			}
			else {
				return 0;
			}
		}
		else if (d == r1 + r2) {
			return 1;
		}
		else {  // d > r1 + r2
			return 0;
		}
	}
}


int main()
{
	int T;
	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		printf("%d\n", solve());
	}
}