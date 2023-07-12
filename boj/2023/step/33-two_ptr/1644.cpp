using namespace std;
#include <cstdio>
#include <vector>

int N;
bool np[4000001];
vector<int> p;
void eratos()
{
	np[0] = np[1] = true;
	for (int i = 2; i <= N; i++) {
		if (!np[i]) {
			p.push_back(i);
			for (int j = 2 * i; j <= N; j += i) {
				np[j] = true;
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	eratos();

	int ans = 0, sum = 0;
	int i = 0, j = 0;
	while (true) {
		if (sum == N) {
			ans++;
		}
		if (sum <= N) {
			if (j == p.size()) {
				break;
			}
			sum += p[j++];
		}
		else {
			sum -= p[i++];
		}
	}
	printf("%d", ans);
}