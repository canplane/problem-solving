// 일부러 틀린 것.
// strstr만 써서 하면 TLE.

#include <cstdio>
#include <cstring>

#define getline(s) __getline((s), sizeof(s))
void __getline(char *s, size_t sz) {
	fgets(s, sz, stdin), s[strcspn(s, "\n")] = '\0';
}

char haystack[1 << 20], needle[1 << 20];
int pos[1 << 20], cnt;

int main()
{
	getline(haystack), getline(needle);

	char *p = haystack - 1;
	while ((p = strstr(p + 1, needle))) {
		pos[cnt++] = p - haystack;
	}
	
	printf("%d\n", cnt);
	for (int i = 0; i < cnt; i++) {
		printf("%d ", pos[i] + 1);
	}
}