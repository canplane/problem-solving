#include <cstdio>

char l[600000], r[600000];  // 명령어는 최대 500000번 가능!
int lsz, rsz;

void push(char s[], int *sz, char x) {
    s[(*sz)++] = x;  // *sz++는 포인터 증가시키면서 그 값 불러오는 것. 다르다!
}
int pop(char s[], int *sz) {
    return s[--(*sz)];
}

int main()
{
    char s[2], c;
    int N, i;
    while ((c = getchar()) != '\n') l[lsz++] = c;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        switch (s[0]) {
        case 'L':
            if (lsz) push(r, &rsz, pop(l, &lsz));
            break;
        case 'D':
            if (rsz) push(l, &lsz, pop(r, &rsz));
            break;
        case 'B':
            if (lsz) pop(l, &lsz);
            break;
        case 'P':
            scanf("%s", s);
            push(l, &lsz, s[0]);
            break;
        }
    }
    while (rsz) {
        push(l, &lsz, pop(r, &rsz));
    }
    for (i = 0; i < lsz; i++) putchar(l[i]);
}