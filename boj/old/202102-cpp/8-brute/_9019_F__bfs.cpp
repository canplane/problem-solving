// 이건 왜 틀렸습니다지? : 0도 저장할 수 있어서 그런 듯.

#include <cstdio>
#include <queue>

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
            for (int i = B, l, r = -1; i != -1; r = i, i = l)
                l = prev[i], prev[i] = r;
            for (int i = A; prev[i] != -1; i = prev[i]) {
                if (prev[i] == D(i))
                    putchar('D');
                else if (prev[i] == S(i))
                    putchar('S');
                else if (prev[i] == L(i))
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