using namespace std;
#include <cstdio>

bool nself[10051];

int d(int n)
{
	int ret = n;
	for (; n; n /= 10) {
		ret += n % 10;
	}
	return ret;
}

int main()
{
	for (int i = 1; i <= 10000; i++) {
		nself[d(i)] = true;	
	}
	for (int i = 1; i <= 10000; i++) {
		if (!nself[i]) {
			printf("%d\n", i);
		}
	}
}