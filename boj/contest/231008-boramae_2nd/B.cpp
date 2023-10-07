// [20분 걸림? 바보] 역시 구현이 약하다.

using namespace std;
#include <bits/stdc++.h>

int sol()
{
	long N, M, P;
	scanf("%ld %ld %ld", &N, &M, &P);

	while (N--) {
		int items = 0;
		vector<long> v;

		for (int i = 0; i < M; i++) {
			long x;
			scanf("%ld", &x);
			if (x == -1) {
				items++;
			}
			else {
				v.push_back(x);
			}
		}
		sort(v.begin(), v.end());

		for (long x : v) {
			while (true) {
				if (x <= P) {
					P += x;
					//printf("x=%ld P=%ld items=%d\n", x, P, items);
					break;
				}
				else {
					if (items > 0) {
						P *= 2, items -= 1;
					}
					else {
						return 0;
					}
				}
			}
		}
		while (items > 0) {
			P *= 2, items -= 1;
		}
	}
	return 1;
}
int main()
{
	printf("%d", sol());
}