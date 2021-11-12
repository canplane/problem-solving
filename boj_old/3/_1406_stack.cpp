#include <cstdio>
#include <stack>

int main()
{
    int N, i;
    std::stack<char> l, r;  // stack이 생각보다 빠르다! 따로 구현할 필요 없는 듯.
    char s[20], c;

    while ((c = getchar()) != '\n') l.push(c);
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        switch (s[0]) {
        case 'L':
            if (l.size()) r.push(l.top()), l.pop();
            break;
        case 'D':
            if (r.size()) l.push(r.top()), r.pop();
            break;
        case 'B':
            if (l.size()) l.pop();
            break;
        case 'P':
            scanf("%s", s);
            l.push(s[0]);
            break;
        }
    }
    while (l.size()) {
        r.push(l.top()), l.pop();
    }
    while (r.size()) putchar(r.top()), r.pop();
}