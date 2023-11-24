using namespace std;
#include <bits/stdc++.h>

int N;
vector<pair<int, int>> candidates;

bool rb[20], lb[20];
#define SAFE(y, x) (!rb[N + ((y) - (x))] && !lb[(y) + (x)])
#define MARK(y, x, b) (rb[N + ((y) - (x))] = lb[(y) + (x)] = (b))
int bt(int i)
{
	int ret = 0;
	for (int j = i; j < candidates.size(); j++) {
		auto [y0, x0] = candidates[j];
		if (SAFE(y0, x0)) {
			MARK(y0, x0, true);
			ret = max(ret, 1 + bt(j + 1));
			MARK(y0, x0, false);
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &N);

	int b;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			scanf("%d", &b);
			if (b) {
				candidates.push_back({ y, x });
			}
		}
	}
	
	printf("%d", bt(0));
}