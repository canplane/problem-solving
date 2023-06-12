/*
	투 포인터 (2848 ms) : 안 한 경우 (10092 ms)
*/

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
			AB.push_back(A[i] + B[j]), CD.push_back(-(C[i] + D[j]));
		}
	}
	sort(AB.begin(), AB.end()), sort(CD.begin(), CD.end());

	long cnt = 0;
	long i = 0, j = 0;
	while (i < AB.size() && j < CD.size()) {
		if (AB[i] == CD[j]) {
			long i_l = i, j_l = j;
			while (i < AB.size() && AB[i] == AB[i_l])	i++;
			while (j < CD.size() && CD[j] == CD[j_l])	j++;
			cnt += (i - i_l) * (j - j_l);	// 틀린 요인: overflow
		}
		else {
			if (AB[i] < CD[j])
				i++;
			else
				j++;
		}
	}
	printf("%ld", cnt);
}