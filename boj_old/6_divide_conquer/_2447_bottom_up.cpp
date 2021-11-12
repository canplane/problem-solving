#include <cstdio>

char star(int y, int x) {
    if (!y && !x)
        return '*';
    if (y % 3 == 1 && x % 3 == 1)
        return ' ';
    return star(y / 3, x / 3);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++)
            printf("%c", star(y, x));
        printf("\n");
    }
}