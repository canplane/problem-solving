// mp[key]로 접근하면 있든 없든 생성하게 됨. mp.count(key)로 있는지 없는지 파악하면 된다.
// key에 해당하는 value가 있으면 1, 없으면 0 반환!

#include <cstdio>
#include <map>
using namespace std;

int A[1001], B[1001], n, m, T;
long long ans;
map<int, int> mp;  // 로컬에 있어도 key 처음 생성할 때 널 값으로 시작하는 듯!

int main() {
	scanf("%d", &T);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &A[i]), A[i] += A[i - 1];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
		scanf("%d", &B[i]), B[i] += B[i - 1];

	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			mp[A[j] - A[i]]++;
	for (int i = 0; i <= m; i++)
		for (int j = i + 1, tmp; j <= m; j++)
			if (mp.count(tmp = T - (B[j] - B[i])))
				ans += mp[tmp];
	printf("%lld", ans);
}