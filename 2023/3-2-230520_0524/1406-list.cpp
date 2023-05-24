#include <cstdio>
#include <list>
using namespace std;

char s[100001];

list<char> li;

int main()
{
	int i;
	
	scanf("%s", s);
	for (i = 0; s[i]; i++)
		li.push_back(s[i]);

	int N;
	scanf("%d", &N);

	list<char>::iterator it = li.end();
	while (N--) {
		scanf("%s", s);
		switch (s[0]) {
		case 'P':
			scanf("%s", s);
			li.insert(it, s[0]);
			break;
		case 'L':
			if (it != li.begin())  --it;
			break;
		case 'D':
			if (it != li.end())    ++it;
			break;
		case 'B':
			if (it != li.begin())  it = li.erase(--it);
			break;
		}
	}

	for (it = li.begin(); it != li.end(); ++it)
		printf("%c", *it);
}