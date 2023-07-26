#include <cstdio>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    printf("%d\n", (A+B)%C);
    printf("%d\n", ((A%C)+(B%C))%C);  // 위와 같다.
    printf("%d\n", (A*B)%C);
    printf("%d\n", ((A%C)*(B%C))%C);  // 위와 같다.
}