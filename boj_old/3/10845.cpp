#include <cstdio>
#include <cstring>
#define MAXSZ 10001

struct queue {
    int data[MAXSZ], _front = 0, _rear = 0, _size;
    bool enqueue(int x) {
        int tmp = (_rear + 1) % MAXSZ;
        if (tmp == _front) return false;
        data[_rear = tmp] = x;
        _size++;
        return true;
    }
    void dequeue() {
        _front = (_front + 1) % MAXSZ;
        _size--;
    }
    bool empty() { return _front == _rear; }
    int front() { return data[(_front + 1) % MAXSZ]; }
    int rear() { return data[_rear]; }
    int size() { return _size; }
} q;

int main()
{
    int N, x;
    char str[6];
    scanf("%d", &N);
    while (N--) {
        scanf("%s", str);
        if (!strcmp(str, "push")) {
            scanf("%d", &x);
            q.enqueue(x);
        } else if (!strcmp(str, "pop")) {
            if (q.size()) {
                printf("%d\n", q.front());
                q.dequeue();
            } else {
                printf("%d\n", -1);
            }
        } else if (!strcmp(str, "size")) printf("%d\n", q.size());
        else if (!strcmp(str, "empty")) printf("%d\n", q.empty());
        else if (!strcmp(str, "front")) printf("%d\n", q.size() ? q.front() : -1);
        else printf("%d\n", q.size() ? q.rear() : -1);
    }
}