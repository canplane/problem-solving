/*
	binary search는 convex function일 때는 대칭(즉, 이차함수)일 때만 활용 가능!
	즉, 이 문제는 binary search로 풀 수도 있다.
*/

#include <cstdio>
#include <cmath>
struct Point { double x, y; };
Point operator+(Point A, Point B) { return { A.x + B.x, A.y + B.y }; }
Point operator-(Point A, Point B) { return { A.x - B.x, A.y - B.y }; }
Point operator*(Point A, Point B) { return { A.x * B.x, A.y * B.y }; }
Point operator*(double k, Point A) { return { k * A.x, k * A.y }; }
Point operator/(Point A, Point B) { return { A.x / B.x, A.y / B.y }; }
Point operator/(Point A, double k) { return { A.x / k, A.y / k }; }
double norm(Point A) { return sqrt(pow(A.x, 2) + pow(A.y, 2)); }
bool equal(Point A, Point B) { return norm(B - A) < 1e-6; }
Point div(Point A, Point B, double m, double n) { return (m * B + n * A) / (m + n); }

double _lower_bound(Point A, Point B)
{
	Point M;
	while (!equal(A, B)) {
		M = (A + B) / 2;
		if (norm(A) <= norm(B))
			B = M;
		else
			A = M;
	}
	return norm(A);
}

int main()
{
	Point A, B;
	double x, y;
	scanf("%lf %lf", &x, &y), A.x = x, A.y = y;
	scanf("%lf %lf", &x, &y), B.x = x, B.y = y;
	scanf("%lf %lf", &x, &y), A.x -= x, A.y -= y;
	scanf("%lf %lf", &x, &y), B.x -= x, B.y -= y;

	printf("%.10lf", _lower_bound(A, B));
}