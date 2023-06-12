using namespace std;
#include <cstdio>
#include <cstring>
#include <algorithm>

char A[100001];

int sum()
{
	int ret = 0;
	for (int i = 0; A[i]; i++)
		ret += A[i] - '0';
	return ret;
}

int main()
{
	scanf("%s", A);
	int N = strlen(A);
	sort(A, A + N, greater());
	if (A[N - 1] == '0' && sum() % 3 == 0)
		printf("%s", A);
	else
		printf("-1");
}