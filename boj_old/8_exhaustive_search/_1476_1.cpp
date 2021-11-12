// year = 15x + E = 28y + S = 19z + M

#include <cstdio>

int main() {
    int E, S, M;
    scanf("%d %d %d", &E, &S, &M);

    int year = 1;
    while ((year - E) % 15 || (year - S) % 28 || (year - M) % 19)
        year++;
    printf("%d", year);
}