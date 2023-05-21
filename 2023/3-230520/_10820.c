/*
	* 틀린 요인
		* 버퍼 크기: s[101] 아니라 s[102]
	* 참고
		* > s[strcspn(s, "\n")] = 0;
		* ' ' == 32 == 0x20, '\n' == 10 == 0x0A
*/


#include <stdio.h>
#include <string.h>

char s[102];
int cnt[4];

int main()
{
	int i;
	while (fgets(s, 102, stdin)) {
		s[strcspn(s, "\n")] = 0;
		for (i = 0; i < 4; i++) cnt[i] = 0;
		for (i = 0; s[i]; i++) {
			if (97 <= s[i] && s[i] < 97 + 26)
				cnt[0]++;
			else if (65 <= s[i] && s[i] < 65 + 26)
				cnt[1]++;
			else if (48 <= s[i] && s[i] < 48 + 10)
				cnt[2]++;
			else
				cnt[3]++;
		}
		for (i = 0; i < 4; i++)
			printf("%d ", cnt[i]);
		printf("\n");
	}
}