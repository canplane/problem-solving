#include <cstdio>

void hanoi(int from, int to, int height) {
    if (!height)
        return;
    hanoi(from, 6 - from - to, height - 1);  // 합이 6임을 이용
    printf("%d %d\n", from, to);
    hanoi(6 - from - to, to, height - 1);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", (1 << N) - 1);
    hanoi(1, 3, N);
}