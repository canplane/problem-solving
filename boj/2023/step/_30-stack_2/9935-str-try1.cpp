using namespace std;
#include <cstdio>
#include <deque>
#include <utility>

char haystack[1000001], needle[37];
deque<pair<char, int>> st;

int main()
{
	scanf("%s %s", haystack, needle);

	int j = 0;
	for (int i = 0; haystack[i]; i++) {
		if (haystack[i] == needle[j]) {
			j++;
		}
		else {
			j = haystack[i] == needle[0];
		}
		st.push_back({ haystack[i], j });
		if (!needle[j]) {
			while (j--) {
				st.pop_back();
			}
			j = st.empty() ? 0 : st.back().second;
		}
	}
	if (st.empty()) {
		puts("FRULA");
	}
	else {
		while (!st.empty()) {
			putchar(st.front().first), st.pop_front();
		}
	}
}