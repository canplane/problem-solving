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
    int tmp = (_front - 1) % MAXSZ;
    if (_back == tmp) return false;
    deque[_front] = x, _front = tmp;
    _size++;
    return true;
}
void pop_front() {  // dequeue
    _front = (_front + 1) % MAXSZ;
    _size--;
}
void pop_back() {  // pop
    _back = (_back - 1) % MAXSZ;
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
    int N, x;
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
            printf("%d\n", front());
        else
            printf("%d\n", back());
    }
}