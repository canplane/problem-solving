using namespace std;
#include <bits/stdc++.h>

#define D(a, b) (abs((a).first - (b).first) + abs((a).second - (b).second))
int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	vector<pair<int, int>> ho, ch;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			int e;
			scanf("%d", &e);
			if (e == 1)
				ho.push_back({ y, x });
			else if (e == 2)
				ch.push_back({ y, x });
		}
	}

	vector<bool> comb(M, true);
	comb.resize(ch.size());
	int ans = INT_MAX;
	do {
		vector<int> dist(ho.size(), INT_MAX);
		for (int i = 0; i < comb.size(); i++)
			if (comb[i])
				for (int j = 0; j < dist.size(); j++)
					dist[j] = min(dist[j], D(ho[j], ch[i]));
		int sum = 0;
		for (int &d : dist)
			sum += d;
		ans = min(ans, sum);
	} while (prev_permutation(begin(comb), end(comb)));
	printf("%d", ans);
}