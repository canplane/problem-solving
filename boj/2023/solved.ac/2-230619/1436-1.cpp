// 문자열 돌리면 더 느림 (20 ms -> 200 ms!)

#include <cstdio>
#include <cstring>

int N, n, k;
char s[101];

int main()
{
	scanf("%d", &N);
	while ((k += !!strstr(s, "666")) != N)
		sprintf(s, "%d", ++n);
	printf("%d", n);
}