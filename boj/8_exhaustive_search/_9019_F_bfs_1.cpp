#include <cstdio>
#include <queue>
#include <stack>

#define D(x) ((2 * (x)) % 10000)
#define S(x) (((x) + 9999) % 10000)
#define L(x) (((x) * 10) % 10000 + ((x) / 1000) % 10)
#define R(x) (((x) / 10) + ((x) % 10) * 1000)

void bfs(int A, int B) {
    std::queue<int> q;
    int prev[10000] = {};

    prev[A] = -1, q.push(A);
    while (!q.empty()) {
        int X, Y;
        X = q.front(), q.pop();
        if (X == B) {
            std::stack<int> s;
            for (int i = B; i != A; i = prev[i])
                s.push(i);  // 메모리 초과 : stack 때문에 터지는 듯.
            for (int i = A, next; !s.empty(); i = next) {
                next = s.top(), s.pop();
                if (next == D(i))
                    putchar('D');
                else if (next == S(i))
                    putchar('S');
                else if (next == L(i))
                    putchar('L');
                else
                    putchar('R');
            }
            printf("\n");
            return;
        }
        if (!prev[Y = D(X)])
            prev[Y] = X, q.push(Y);
        if (!prev[Y = S(X)])
            prev[Y] = X, q.push(Y);
        if (!prev[Y = L(X)])
            prev[Y] = X, q.push(Y);
        if (!prev[Y = R(X)])
            prev[Y] = X, q.push(Y);
    }
}

int main() {
    int T, A, B;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &A, &B);
        bfs(A, B);
    }
}