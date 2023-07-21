#include <bits/stdc++.h>

char dst[1000001], haystack[1000001], needle[37];
int k, i, len;

int main()
{
	scanf("%s%s", haystack, needle);
	len = strlen(needle);

	while (haystack[i]) {
		dst[k++] = haystack[i++];
		if (k >= len && !strncmp((dst + k) - len, needle, len))
			k -= len;
	}
	dst[k] = 0;
	puts(k ? dst : "FRULA");
}