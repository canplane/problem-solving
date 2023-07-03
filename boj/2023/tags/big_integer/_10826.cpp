// 큰 수 연산: 10000번째 피보나치 수

using namespace std;
#include <cstdio>
#include <string>

void _add(string& $c, int& s, int& c)
{
	c = s >= 10 ? s / 10 : 0, s %= 10;
	$c += string(1, s + '0');
}
void add(string& $c, string& $a, string& $b)
{
	int s, c = 0;
	int k = 0;
	for (; k < $a.size() && k < $b.size(); k++)
		s = c + ($a[k] - '0') + ($b[k] - '0'), _add($c, s, c);
	for (; k < $a.size(); k++)
		s = c + ($a[k] - '0'), _add($c, s, c);
	for (; k < $b.size(); k++)
		s = c + ($b[k] - '0'), _add($c, s, c);
	if (c > 0)
		s = c, _add($c, s, c);
}

string f[10001];

int main()
{
	f[0] = "0", f[1] = "1";
	for (int i = 2; i <= 10000; i++)
		add(f[i], f[i - 1], f[i - 2]);

	int n;
	scanf("%d", &n);
	for (auto it = f[n].rbegin(); it != f[n].rend(); it++)
		printf("%c", *it);
}