#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/*
27711
2|7711
2|1177
[7]|11[2]7

1324
132|4
*/

char s[10];

int main()
{
    scanf("%s", s);
    int len = strlen(s);

    int asc = -1;
    for (int i = 0; i < len - 1; i++) {
        if (s[i] < s[i + 1]) {
            asc = i;
        }
    }

    if (asc == -1)
        printf("0");
    else {
        sort(s + asc + 1, s + len);
        for (int i = asc + 1; i < len; i++) {
            if (s[asc] < s[i]) {
                swap(s[asc], s[i]);
                break;
            }
        }
        printf("%s", s);
    }
}