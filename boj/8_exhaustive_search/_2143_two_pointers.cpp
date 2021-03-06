/*
BOJ 2003 :
두 포인터를 조작하여 부분합을 구할 수 있는 이유는 배열의 값이 자연수이기 때문.
자연수이므로 end를 증가시키면 부분합이 증가하고, start를 증가시키면 부분합이 감소하는 것을 보장할 수 있다.
음수가 섞여 있다면 이를 보장할 수 없으므로 two pointers를 사용할 수 없다.

BOJ 2143 :
이 문제는 음수가 섞여 있으므로 위처럼 구할 수는 없으나,
A, B에서 각각 가능한 합들을 sA, sB에 저장해서 sA는 왼쪽부터, sB는 오른쪽부터 시작해서
같은지 비교해 나가는 방법으로 두 포인터를 이용할 수 있다.
 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000], B[1000], n, m, T;
vector<int> sA, sB;
long long ans;

int main() {
	scanf("%d", &T);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &A[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &B[i]);

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++)
			sA.push_back(sum += A[j]);
	}
	for (int i = 0; i < m; i++) {
		int sum = 0;
		for (int j = i; j < m; j++)
			sB.push_back(sum += B[j]);
	}
	sort(sA.begin(), sA.end()), sort(sB.begin(), sB.end());
	
	int l = 0, r = sB.size() - 1;
	while (true) {
		if (sA[l] + sB[r] < T)
			l++;
		else if (sA[l] + sB[r] > T)
			r--;
		else {
			long long cnt_l = 1, cnt_r = 1;
			while (l + 1 < sA.size() && sA[l] == sA[l + 1])
				l++, cnt_l++;
			while (r - 1 >= 0 && sB[r] == sB[r - 1])
				r--, cnt_r++;
			ans += cnt_l * cnt_r;
			l++, r--;
		}
		if (l >= sA.size() || r < 0)
			break;
	}
	printf("%lld", ans);
}