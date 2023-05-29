#include <cstdio>
#include <algorithm>
using namespace std;

char s[100001];

int main()
{
    scanf("%s", s);
    
    int cnt = 0, idx_zero = -1;
    int i;
    for (i = 0; s[i]; i++) {
        cnt += s[i] - '0';
        if (s[i] == '0')    idx_zero = i;
    }
    if ((cnt % 3) || idx_zero == -1) {
        puts("-1");
    }
    else {
        swap(s[idx_zero], s[i - 1]);
        sort(s, s + i - 1, greater());
        puts(s);
    }
}