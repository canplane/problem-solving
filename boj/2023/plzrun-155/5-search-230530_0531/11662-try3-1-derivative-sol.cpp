#include <cstdio>
#include <cmath>

struct Point { double x, y; } A, B;

#define dPx (B.x - A.x)
#define dPy (B.y - A.y)
#define Px(t) (A.x + dPx * t)
#define Py(t) (A.y + dPy * t)

#define F(t) (pow(Px(t), 2) + pow(Py(t), 2))

double sol(double t1, double t2)
{
	double t = (dPx || dPy) ? -(dPx * A.x + dPy * A.y) / (dPx * dPx + dPy * dPy) : t1;
	if (t < t1)			t = t1;
	else if (t2 < t)	t = t2;
	return sqrt(F(t));
}

int main()
{
	double x, y;
	scanf("%lf %lf", &x, &y), A.x = x, A.y = y;
	scanf("%lf %lf", &x, &y), B.x = x, B.y = y;
	scanf("%lf %lf", &x, &y), A.x -= x, A.y -= y;
	scanf("%lf %lf", &x, &y), B.x -= x, B.y -= y;
	
	printf("%.10lf", sol(0, 1));
}