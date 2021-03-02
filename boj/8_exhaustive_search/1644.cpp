#include <cstdio>
#include <vector>

bool eratos[4000001];
int N;
std::vector<int> p;

int main() {
	scanf("%d", &N);
	for (int i = 2; i <= N; i++)
		if (!eratos[i]) {
			p.push_back(i);
			for (int j = 2 * i; j <= N; j += i) eratos[j] = true;
		}

	int ans = 0, sum = 0, l = 0, r = 0;
	while (true) {
		if (sum == N) ans++;
		if (sum >= N) sum -= p[l++];
		else if (r == p.size()) break;
		else sum += p[r++];
	}
	printf("%d", ans);
}