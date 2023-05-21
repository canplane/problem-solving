#include <stdio.h>
#include <string.h>

char cmd[100];
int x;

#define MAXSZ 10000
int deq[MAXSZ];
int _front, _back, _size;
void push_back(int e)
{
	int tmp = (_back + 1) % MAXSZ;
	if (tmp == _front)
		return;
	_size++;
	deq[_back = tmp] = e;
}
void push_front(int e)
{
	int tmp = (_front - 1 + MAXSZ) % MAXSZ;
	if (tmp == _back)
		return;
	_size++;
	deq[_front] = e;
	_front = tmp;
}
void pop_front()
{
	if (_front == _back)
		return;
	_size--;
	_front = (_front + 1) % MAXSZ;
}
void pop_back()
{
	if (_back == _front)
		return;
	_size--;
	_back = (_back - 1 + MAXSZ) % MAXSZ;
}
int front() { return deq[(_front + 1) % MAXSZ]; }
int back()  { return deq[_back]; }
int size()  { return _size; }
int empty() { return !_size; }


int main()
{
	int N;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "push_back")) {
			scanf("%d", &x);
			push_back(x);
		}
		else if (!strcmp(cmd, "push_front")) {
			scanf("%d", &x);
			push_front(x);
		}
		else if (!strcmp(cmd, "pop_front")) {
			if (!empty())
				x = front(), pop_front();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "pop_back")) {
			if (!empty())
				x = back(), pop_back();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "front")) {
			if (!empty())
				x = front();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "back")) {
			if (!empty())
				x = back();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", empty());
		}
	}
}