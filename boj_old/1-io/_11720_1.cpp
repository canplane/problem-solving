#include <cstdio>

int main()
{
    int n, sum = 0;
    scanf("%d%*c", &n);  // *는 받기만 하고 할당은 하지 않는 것.
    while (n--)
        sum += getchar() - '0';
    printf("%d", sum);
}