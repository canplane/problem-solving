/*
	틀린다. 이걸로는 정확하지 않거나 iter가 작아 못 푸는 듯. 늘리면 시간 초과
	gradient descent: alpha 잡기 힘들고 모든 TC 통과한다는 보장은 없으니 좋지 않음
	
	Q. 삼분 탐색 왜 안 쓰고 느린 경사 하강법 쓰는건가?
	삼분 탐색은 1차원 convex 함수에서만 적용 가능. 고차원 함수에는 적용할 수 없는 기법	
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

const double alpha = 1e-12;
const double t_m = 0, t_M = 1;
double t = t_m + (t_M - t_m) / 2;
void gd(int epoch)
{
	for (int _ = 0; _ < epoch; _++) {
		t -= alpha * dF(t);
		if (t < t_m) {
			t = t_m;
			return;
		}
		if (t > t_M) {
			t = t_M;
			return;
		} 
	}
}

int main()
{
	double x, y;
	scanf("%lf %lf", &x, &y), A.x = x, A.y = y;
	scanf("%lf %lf", &x, &y), B.x = x, B.y = y;
	scanf("%lf %lf", &x, &y), A.x -= x, A.y -= y;
	scanf("%lf %lf", &x, &y), B.x -= x, B.y -= y;
	
	gd(10000000);
	printf("%.10lf", sqrt(F(t)));
}