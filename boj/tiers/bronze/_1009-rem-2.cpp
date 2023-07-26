using namespace std;
#include <cstdio>
#include <vector>

vector<int> v[10] = {
	{ 0 },
	{ 1 },
	{ 6, 2, 4, 8 },
	{ 1, 3, 9, 7 },
	{ 6, 4 },
	{ 5 },
	{ 6 },
	{ 1, 7, 9, 3 },
	{ 6, 8, 4, 2 },
	{ 1, 9 },	
};

int f(int a, int b)
{
	a %= 10;
	b %= v[a].size();
	return (v[a][b] + (10 - 1)) % 10 + 1;
}

int main()
{
	int T;
	scanf("%d", &T);

	int a, b;
	while (T--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", f(a, b));
	}
}