#include <cstdio>

bool img[3072][6143], patch[3][5] = {
    { false, false, true, false, false },
    { false, true, false, true, false },
    { true, true, true, true, true }
};

void star(int y, int x, int h) {
    if (h == 3) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 5; j++)
                img[y + i][x + j] = patch[i][j];
        return;
    }
    h /= 2;
    star(y, x + h, h);
    star(y + h, x, h), star(y + h, x + 2 * h, h);
}

int main() {
    int N;
    scanf("%d", &N);
    star(0, 0, N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < 2 * N - 1; x++)
            printf("%c", img[y][x] ? '*' : ' ');
        printf("\n");
    }
}