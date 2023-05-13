#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int d[] = { 9, 4, 8, 7, 2, 1, 6, 5, 0, 3 };

bool _lt(int a, int b)
{
	string sa = to_string(a), sb = to_string(b);
	int i;
	for (i = 0; sa[i] && sb[i]; i++) {
		if (sa[i] != sb[i])	return d[sa[i] - '0'] < d[sb[i] - '0'];
	}
	return sa[i] < sb[i];
}

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);

	vector<int> v;
	for (int i = M; i <= N; i++)    v.push_back(i);
	sort(v.begin(), v.end(), _lt);

	for (int i = 0; i < v.size(); i++) {
		printf("%d ", v[i]);
		if (i % 10 == 9)    puts("");
	}
}