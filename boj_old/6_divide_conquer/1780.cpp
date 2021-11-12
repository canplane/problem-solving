#include <cstdio>

int map[2187][2187];
int pieces[3];

void cut(int Py, int Px, int len) {
    int prev = map[Py][Px];
    for (int y = Py; y < Py + len; y++) {
        for (int x = Px; x < Px + len; x++) {
            if (prev != map[y][x]) {
                len /= 3;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        cut(Py + i * len, Px + j * len, len);
                    }
                }
                return;
            }
            prev = map[y][x];
        }
    }
    ++pieces[map[Py][Px] + 1];
}

int main() {
    int N;
    scanf("%d", &N);
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            scanf("%d", &map[y][x]);
        }
    }
    cut(0, 0, N);
    for (int i = 0; i < 3; i++)
        printf("%d\n", pieces[i]);
}