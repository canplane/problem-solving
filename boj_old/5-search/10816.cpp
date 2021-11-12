#include <cstdio>

int cards[20000001];

int main() {
    int N, tmp;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tmp);
        ++cards[tmp + 10000000];
    }
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &tmp);
        printf("%d ", cards[tmp + 10000000]);
    }
}