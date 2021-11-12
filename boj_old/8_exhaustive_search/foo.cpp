#include <cstdio>

int main() {
    for (int i = 2; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%d * %d = %d\n", i, j, i * j);
            if (i == 4)
                goto outer;        
        }
    }
    outer:
    printf("end\n");
}
