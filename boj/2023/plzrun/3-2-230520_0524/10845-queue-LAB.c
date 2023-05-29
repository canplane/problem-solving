#include <stdio.h>
#include <string.h>

char buf[100];

int N;
char s[100];
int x;

#define MAXSZ 10000
int q[MAXSZ];
int _front, _back, _size;
void push_back(int e)
{
	int tmp = (_back + 1) % MAXSZ;
	if (tmp == _front)
		return;
	_size++;
	q[_back = tmp] = e;
}
void pop_front()
{
	if (_back == _front)
		return;
	_size--;
	_front = (_front + 1) % MAXSZ;
}
int front()	{ return q[(_front + 1) % MAXSZ]; }
int back()	{ return q[_back]; }
int size()	{ return _size; }
int empty() { return !_size; }


int main()
{
	fgets(buf, 100, stdin), sscanf(buf, "%d", &N);
	while (N--) {
		fgets(buf, 100, stdin), sscanf(buf, "%s %d", s, &x);
		if (!strcmp(s, "push")) {
			push_back(x);
		}
		else if (!strcmp(s, "pop")) {
			if (!empty())
				x = front(), pop_front();
			else
				x = -1;
			printf("%d\n", x);
		}
		else if (!strcmp(s, "front")) {
			x = empty() ? -1 : front();
			printf("%d\n", x);
		}
		else if (!strcmp(s, "back")) {
			x = empty() ? -1 : back();
			printf("%d\n", x);
		}
		else if (!strcmp(s, "size")) {
			printf("%d\n", size());
		}
		else if (!strcmp(s, "empty")) {
			printf("%d\n", empty());
		}
	}
}