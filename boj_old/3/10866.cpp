/**
 * 음수에 모듈러 연산하면 음수 나온다. : (0 - 1) % N == -1
 * A = BQ + R에서 Q = A/B.  ->  -5 % 3이라 하면, -5 = 3 * (-5/3 = -1) + -2
 * 그러면 -5 % -3 = ?  ->  -5/-3 = 1이므로 -5 = -3 * 1 - 2  ->  따라서 -5 % -3 = -2  ->  A % -B = A % B
 */

#include <cstdio>
#include <cstring>
#define MAXSZ 10001

int deque[MAXSZ], _front, _back, _size;
bool push_back(int x) {  // enqueue, push
    int tmp = (_back + 1) % MAXSZ;
    if (_front == tmp) return false;
    deque[_back = tmp] = x;
    _size++;
    return true;
}
bool push_front(int x) {
    int tmp = (_front + MAXSZ - 1) % MAXSZ;  // 주의!
    if (_back == tmp) return false;
    deque[_front] = x, _front = tmp;  // 주의!
    _size++;
    return true;
}
void pop_front() {  // dequeue
    _front = (_front + 1) % MAXSZ;
    _size--;
}
void pop_back() {  // pop
    _back = (_back + MAXSZ - 1) % MAXSZ;
    _size--;
}
int size() {
    return _size;
}
bool empty() {
    return _front == _back;
}
int front() {
    return deque[(_front + 1) % MAXSZ];
}
int back() {
    return deque[_back];
}

int main()
{
    /*int N, x;
    char s[11];
    scanf("%d", &N);
    while (N--) {
        scanf("%s", s);
        if (!strcmp(s, "push_front"))
            scanf("%d", &x), push_front(x);
        else if (!strcmp(s, "push_back"))
            scanf("%d", &x), push_back(x);
        else if (!strcmp(s, "pop_front")) {
            if (empty()) printf("-1\n");
            else printf("%d\n", front()), pop_front();
        } else if (!strcmp(s, "pop_back")) {
            if (empty()) printf("-1\n");
            else printf("%d\n", back()), pop_back();
        } else if (!strcmp(s, "size"))
            printf("%d\n", size());
        else if (!strcmp(s, "empty"))
            printf("%d\n", empty());
        else if (!strcmp(s, "front"))
            printf("%d\n", empty() ? -1 : front());
        else
            printf("%d\n", empty() ? -1 : back());
    }*/
    printf("%d", -5 % 3);
}