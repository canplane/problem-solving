#include <cstdio>

int main()
{
    char s[11];
    // scanf는 더 이상 받을 게 없으면 -1을 반환. 0은 더 이용할 수는 있는데 변환할 것이 없다는 것.
    while (~scanf("%10s", s))
        puts(s);
}