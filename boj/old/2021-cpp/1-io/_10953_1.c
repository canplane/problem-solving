#include <stdio.h>

int main()
{
    int t, a, b;
    scanf("%d", &t);
    while (t--) {
        scanf("%d,%d", &a, &b);  // 1, 2 받을 때는 그냥 , 쓰면 된다!
        printf("%d\n", a + b);
    }
}