using namespace std;
#include <iostream>
#include <string>

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string haystack, needle;
	cin >> haystack >> needle;
	
	int pos;
	while ((pos = haystack.find(needle)) != -1) {
		haystack.replace(pos, needle.size(), "");
	}
	cout << (haystack.size() ? haystack : "FRULA");
}