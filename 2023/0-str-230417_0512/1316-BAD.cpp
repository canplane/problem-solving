#include <cstdio>
#include <cstring>

int N, ret;
char s[101];
bool visit[26];

int main()
{
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);

        memset(visit, 0, 26);
        
        int inc = 1;
        char prev = -1;
        for (int i = 0; s[i]; i++) {
            if (prev == s[i])   continue;
            prev = s[i];

            if (visit[s[i] - 'a']) {
                inc = 0;
                break;
            }
            visit[s[i] - 'a'] = true;
        }
        ret += inc;
    }
    printf("%d", ret);
}