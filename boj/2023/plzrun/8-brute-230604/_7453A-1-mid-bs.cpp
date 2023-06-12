using namespace std;
#include <cstdio>
#include <vector>
#include <algorithm>

int n;
int A[4000], B[4000], C[4000], D[4000];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);
	}
	vector<int> AB, CD;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			AB.push_back(A[i] + B[j]), CD.push_back(C[i] + D[j]);
		}
	}
	sort(CD.begin(), CD.end());

	long cnt = 0;
	for (int x : AB) {
		auto it = lower_bound(CD.begin(), CD.end(), -x);
		auto it_r = upper_bound(CD.begin(), CD.end(), -x);
		cnt += it_r - it;
	}
	printf("%d", cnt);
}