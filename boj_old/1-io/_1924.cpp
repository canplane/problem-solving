#include <iostream>
#include <string>
using namespace std;

int d[] = { 0, 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };
string days[] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

int main()
{
	int x, y;
	cin >> x >> y;

	int k = (d[x] + y) % 7;
	cout << days[k] << '\n';

	return 0;
}