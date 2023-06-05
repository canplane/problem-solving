/* CCW를 쓰지 않아 틀리는 것으로 보인다. */

using namespace std;
#include <cstdio>
#include <algorithm>

int main()
{
	int ans;
	double ans_x, ans_y;

	int x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
	scanf("%d %d %d %d", &x3, &y3, &x4, &y4);

	if ((x1 == x2 && y1 > y2) || x1 > x2)	swap(x1, x2), swap(y1, y2);
	if ((x3 == x4 && y3 > y4) || x3 > x4)	swap(x3, x4), swap(y3, y4);

	long dx1 = x2 - x1, dy1 = y2 - y1;
	long dx3 = x4 - x3, dy3 = y4 - y3;

	long Px = dx1 * (x4 * y3 - y4 * x3) - dx3 * (x2 * y1 - y2 * x1);
	long Py = dy1 * (x4 * y3 - y4 * x3) - dy3 * (x2 * y1 - y2 * x1);
	long P = dx3 * dy1 - dx1 * dy3;

	if (P == 0) {
		if (Px == 0) {	// 일치
			if (dx1 == 0) {
				if (y4 == y1)					ans = 1, ans_x = x1, ans_y = y1;
				else if (y2 == y3)				ans = 1, ans_x = x3, ans_y = y3;
				else if (y4 < y1 || y2 < y3)	ans = 0;
				else							ans = -1;
			}
			else {
				if (x4 == x1)					ans = 1, ans_x = x1, ans_y = y1;
				else if (x2 == x3)				ans = 1, ans_x = x3, ans_y = y3;
				else if (x4 < x1 || x2 < x3)	ans = 0;
				else							ans = -1;
			}
		}
		else {	// 평행
			ans = 0;
		}
	}
	else {	// 교차
		ans = 1, ans_x = (double)Px / P, ans_y = (double)Py / P;
		if ((dx1 == 0 && (ans_y < y1 || y2 < ans_y)) || (ans_x < x1 || x2 < ans_x))
			ans = 0;
		if ((dx3 == 0 && (ans_y < y3 || y4 < ans_y)) || (ans_x < x3 || x4 < ans_x))
			ans = 0;
		
		if ((x1 == x3 && y1 == y3) || (x2 == x3 && y2 == y3) || (x1 == x4 && y1 == y4) || (x2 == x4 && y2 == y4))
			ans = 1;
		else {
			if (dx1 == 0) {
				if (x3 == x1 && (y1 < y3 && y3 < y2))
					ans = 1;
				if (x4 == x1 && (y1 < y4 && y4 < y2))
					ans = 1;
			}
			else {
				if ((x1 < x3 && x3 < x2) && (x3 - x1) * dy1 == (y3 - y1) * dx1)
					ans = 1;
				if ((x1 < x4 && x4 < x2) && (x4 - x1) * dy1 == (y4 - y1) * dx1)
					ans = 1;
			}
			
			if (dx3 == 0) {
				if (x1 == x3 && (y3 < y1 && y1 < y4))
					ans = 1;
				if (x2 == x3 && (y3 < y2 && y2 < y4))
					ans = 1;
			}
			else {
				if ((x3 < x1 && x1 < x4) && (x1 - x3) * dy3 == (y1 - y3) * dx3)
					ans = 1;
				else if ((x3 < x2 && x2 < x4) && (x2 - x3) * dy3 == (y2 - y3) * dx3)
					ans = 1;
			}
		}
	}
	printf("%d", abs(ans));
	if (ans == 1)
		printf("\n%.10lf %.10lf", ans_x, ans_y);
}