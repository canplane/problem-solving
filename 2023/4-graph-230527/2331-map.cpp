using namespace std;
#include <cstdio>
#include <map>
#include <cmath>

int main()
{
	int A, P;
	scanf("%d %d", &A, &P);

	map<int, int> idx;
	int i = 0, k = A, k1;
	while (idx.find(k) == idx.end()) {
		idx[k] = i;
		for (k1 = 0; k; k1 += pow(k % 10, P), k /= 10);
		k = k1;
		i++;
	}
	printf("%d", idx[k]);
}