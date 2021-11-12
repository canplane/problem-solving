#include <cstdio>
#include <cstring>

struct {
    int data[10000], size = 0;
    void push(int x) { data[size++] = x; }
    int pop() { return size ? data[--size] : -1; }
    int top() { return size ? data[size - 1] : -1; }
} s;

char instr[6];

int main()
{
    int N, x;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", instr);
        if (!strcmp(instr, "push"))
            scanf("%d", &x), s.push(x);
        else if (!strcmp(instr, "pop"))
            printf("%d\n", s.pop());
        else if (!strcmp(instr, "size"))
            printf("%d\n", s.size);
        else if (!strcmp(instr, "empty"))
            printf("%d\n", !s.size);
        else
            printf("%d\n", s.top());
    }
}