using namespace std;
#include <cstdio>
#include <set>
#include <string>
#include <cstring>

set<string, greater<>> m;

char s[6], t[6];
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s %s", s, t);
		if (!strcmp(t, "enter")) {
			m.insert(s);
		}
		else {
			m.erase(s);
		}
	}
	for (auto& s : m) {
		printf("%s\n", s.c_str());
	}
}