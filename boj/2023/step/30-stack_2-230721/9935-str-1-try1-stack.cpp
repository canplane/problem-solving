using namespace std;
#include <cstdio>
#include <stack>
#include <cstring>

char haystack[1000001], needle[37];
stack<char> s, t;

int main()
{
	scanf("%s %s", haystack, needle);
	int len = strlen(needle);

	for (int i = 0; haystack[i]; i++) {
		s.push(haystack[i]);

		bool match = true;
		for (int j = 1; j <= len; j++) {
			if (!(!s.empty() && s.top() == needle[len - j])) {
				match = false;
				break;
			}
			t.push(s.top()), s.pop();
		}
		if (!match)
			while (!t.empty())	s.push(t.top()), t.pop();
		else
			while (!t.empty())	t.pop();
	}
	if (s.empty())
		puts("FRULA");
	else {
		while (!s.empty())	t.push(s.top()), s.pop();
		while (!t.empty())	putchar(t.top()), t.pop();
	}
}