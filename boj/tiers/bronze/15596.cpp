#include <vector>

long sum(std::vector<int> &a)
{
	long ret = 0;
	for (int x : a)
		ret += x;
	return ret;
}