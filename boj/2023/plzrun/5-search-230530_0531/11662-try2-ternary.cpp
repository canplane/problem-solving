/*
	ternary search는 일반적인 convex function이면(즉, 이차함수처럼 대칭이 아니라도) 모두 적용 가능!
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

double _lower_bound_ternary(Point A, Point B)
{
	Point P, Q;
	while (!equal(A, B)) {
		P = div(A, B, 1, 2), Q = div(A, B, 2, 1);
		if (norm(P) <= norm(Q))
			B = Q;
		else
			A = P;
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

	printf("%.10lf", _lower_bound_ternary(A, B));
}