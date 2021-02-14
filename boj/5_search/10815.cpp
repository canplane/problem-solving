/* 이게 왜 이분 탐색이지? */

#include <cstdio>

bool cards[20000001];

int main() {
    int N, tmp;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tmp);
        cards[tmp + 10000000] = true;
    }
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tmp);
        printf("%d ", cards[tmp + 10000000]);
    }
}