#include <cstdio>
#include <cmath>

void hanoi(int from, int to, int buf, int height) {
    if (!height)
        return;
    hanoi(from, buf, to, height - 1);
    printf("%d %d\n", from, to);
    hanoi(buf, to, from, height - 1);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", (int)pow(2, N) - 1);
    hanoi(1, 3, 2, N);
}