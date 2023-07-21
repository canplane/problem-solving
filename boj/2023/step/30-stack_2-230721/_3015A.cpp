using namespace std;
#include <bits/stdc++.h>

stack<pair<long, long>> st;

int main()
{
	long N;
	scanf("%ld", &N);

	long ans = 0;
	while (N--) {
		long x;
		scanf("%ld", &x);

		long cnt = 1;
		while (!st.empty()) {
			auto &[y, y_cnt] = st.top();
			if (y > x) {
				ans++;
				break;
			}
			else if (y < x) {
				ans += y_cnt;
				st.pop();
			}
			else {
				ans += y_cnt;
				cnt += y_cnt;
				st.pop();
			}
		}
		st.push({ x, cnt });
	}
	printf("%ld", ans);
}