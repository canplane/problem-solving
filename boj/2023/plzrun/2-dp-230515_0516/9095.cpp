using namespace std;
#include <cstdio>

long f[12] = { 1, 1, 2 };

int main()
{
	for (int i = 3; i <= 10; i++)
		f[i] = f[i - 1] + f[i - 2] + f[i - 3];

	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		printf("%ld\n", f[n]);
	}
}