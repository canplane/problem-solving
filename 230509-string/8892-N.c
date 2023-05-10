#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct { char *s1, *s2; int l1, l2, l; } S;
S *new_S(char *s1, char *s2) {
    S *s = malloc(sizeof(S));
    s->s1 = s1, s->s2 = s2, s->l1 = strlen(s1), s->l2 = strlen(s2);
    s->l = s->l1 + s->l2;
    return s;
}
#define print_S(s, end) printf("%s%s%s", (s)->s1, (s)->s2, end)
#define S_(s, i) ((i) < (s)->l1 ? (s)->s1[i] : (s)->s2[(i) - (s)->l1])
#define S_len(s) ((s)->l)

char dic[100][10001];
int N;

int is_palindrome(S *s)
{
    int l = S_len(s);
    for (int i = 0; i < l / 2; i++) {
        if (S_(s, i) != S_(s, l - 1 - i)) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        S *s = NULL;
        
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
            scanf("%s", dic[i]);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;
                if (s)  free(s);
                s = new_S(dic[i], dic[j]);
                if (is_palindrome(s)) {
                    print_S(s, "\n");
                    goto FOUND;
                }
            }
        }
        puts("0");
        FOUND:;
    }
}