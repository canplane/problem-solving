/*
	convex function이면 미분으로 풀어도 된다.
*/

#include <cstdio>
#include <cmath>

struct Point { double x, y; } A, B;

#define dPx (B.x - A.x)
#define dPy (B.y - A.y)
#define Px(t) (A.x + dPx * t)
#define Py(t) (A.y + dPy * t)

#define F(t) (pow(Px(t), 2) + pow(Py(t), 2))
#define dF(t) (2 * (Px(t) * dPx + Py(t) * dPy))

double _lower_bound(double t1, double t2)
{
	double t;
	while (t2 - t1 > 1e-12) {
		t = t1 + (t2 - t1) / 2;
		if (dF(t) >= 0)
			t2 = t;
		else
			t1 = t;
	}
	return sqrt(F(t1));
}

int main()
{
	double x, y;
	scanf("%lf %lf", &x, &y), A.x = x, A.y = y;
	scanf("%lf %lf", &x, &y), B.x = x, B.y = y;
	scanf("%lf %lf", &x, &y), A.x -= x, A.y -= y;
	scanf("%lf %lf", &x, &y), B.x -= x, B.y -= y;
	
	printf("%.10lf", _lower_bound(0, 1));
}