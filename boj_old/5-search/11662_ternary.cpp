/* ternary search
 * 
 * 아래로 볼록 함수인 경우, 우선 정의역을 lo, p, q, hi로 3등분한다.
 * f(p) >= f(q)면 [p, hi]에 존재, f(p) <= f(q)면 [lo, q]에 존재.
 */

#include <cstdio>
#include <cmath>
using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double tern_search(double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy) {
    double p, q;

    while (dist(Ax, Ay, Bx, By) > 1e-6 || dist(Cx, Cy, Dx, Dy) > 1e-6) {
        p = dist((Bx + 2 * Ax) / 3, (By + 2 * Ay) / 3, (Dx + 2 * Cx) / 3, (Dy + 2 * Cy) / 3),
        q = dist((2 * Bx + Ax) / 3, (2 * By + Ay) / 3, (2 * Dx + Cx) / 3, (2 * Dy + Cy) / 3);

        if (p > q)
            Ax = (Bx + 2 * Ax) / 3, Ay = (By + 2 * Ay) / 3, 
            Cx = (Dx + 2 * Cx) / 3, Cy = (Dy + 2 * Cy) / 3;
        else
            Bx = (2 * Bx + Ax) / 3, By = (2 * By + Ay) / 3,
            Dx = (2 * Dx + Cx) / 3, Dy = (2 * Dy + Cy) / 3;
    }
    return (p + q) / 2;
}


int main() {
    int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    scanf("%d %d %d %d %d %d %d %d", &Ax, &Ay, &Bx, &By, &Cx, &Cy, &Dx, &Dy);
    printf("%f", tern_search(Ax, Ay, Bx, By, Cx, Cy, Dx, Dy));
}