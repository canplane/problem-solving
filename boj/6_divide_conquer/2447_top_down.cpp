#include <cstdio>

bool img[2187][2187];

void star(int Py, int Px, int width) {
    if (width == 1) {
        img[Py][Px] = true;
        return;
    }
    width /= 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (!(i == 1 && j == 1))
                star(Py + i * width, Px + j * width, width);
}

int main() {
    int N;
    scanf("%d", &N);
    star(0, 0, N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++)
            printf("%c", img[y][x] ? '*' : ' ');
        printf("\n");
    }
}