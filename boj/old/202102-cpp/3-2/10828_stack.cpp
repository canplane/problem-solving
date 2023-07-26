#include <cstdio>
#include <cstring>
#include <stack>

int main()
{
    int N, x;
    char str[6];
    std::stack<int> s;

    scanf("%d", &N);
    while (N--) {
        scanf("%s", str);
        if (!strcmp(str, "push")) {
            scanf("%d", &x);
            s.push(x);
        } else if (!strcmp(str, "pop")) {
            if (s.empty())
                printf("-1\n");
            else {
                printf("%d\n", s.top());
                s.pop();
            }
        } else if (!strcmp(str, "size"))
            printf("%lu\n", s.size());
        else if (!strcmp(str, "empty"))
            printf("%d\n", s.empty());
        else
            printf("%d\n", s.empty() ? -1 : s.top());
    }
}