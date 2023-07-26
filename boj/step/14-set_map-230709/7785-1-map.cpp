using namespace std;
#include <cstdio>
#include <map>
#include <string>
#include <cstring>

map<string, bool, greater<>> m;

char s[6], t[6];
int main()
{
	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s %s", s, t);
		if (!strcmp(t, "enter")) {
			m.insert({ s, true });
		}
		else {
			m.erase(s);
		}
	}
	for (auto& [s, b] : m) {
		if (b) {
			printf("%s\n", s.c_str());
		}
	}
}