#include <cstdio>
#include <cctype>

char c;
int alpha[26];

int main()
{
	while ((c = getchar()) != -1) {
		alpha[toupper(c) - 'A']++;
	}
	int ans = 0;
	bool valid = true;
	for (int i = 1; i < 26; i++) {
		if (alpha[i] > alpha[ans]) {
			ans = i, valid = true;
		}
		else if (alpha[i] == alpha[ans]) {
			valid = false;
		}
	}
	printf("%c", valid ? ans + 'A' : '?');
}