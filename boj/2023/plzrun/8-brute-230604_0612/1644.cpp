using namespace std;
#include <cstdio>
#include <vector>

int N;
bool np[4000001];
vector<int> p;
void eratos()
{
	np[0] = np[1] = true;
	for (int i = 2; i <= 4000000; i++) {
		if (np[i])	continue;
		p.push_back(i);
		for (int j = 2 * i; j <= 4000000; j += i)
			np[j] = true;
	}
}

int main()
{
	eratos();

	scanf("%d", &N);
	int i = 0, j = 0;
	long sum = 0;
	long cnt = 0;
	while (j <= p.size()) {
		cnt += (sum == N);
		if (sum <= N)
			sum += p[j++];
		else
			sum -= p[i++];
	}
	printf("%ld", cnt);
}