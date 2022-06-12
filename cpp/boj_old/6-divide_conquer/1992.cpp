#include <cstdio>

int img[64][64];

void encode(int Py, int Px, int width) {
    int prev = img[Py][Px]; 
    for (int y = Py; y < Py + width; y++) {
        for (int x = Px; x < Px + width; x++) {
            if (prev != img[y][x]) {
                printf("(");
                width /= 2;
                for (int i = 0; i < 2; i++)
                    for (int j = 0; j < 2; j++)
                        encode(Py + i * width, Px + j * width, width);
                printf(")");
                return;
            }
            prev = img[y][x];
        }
    }
    printf("%d", prev);
}

int main() {
    int N;
    scanf("%d", &N);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            scanf("%1d", &img[y][x]);
    encode(0, 0, N);
}