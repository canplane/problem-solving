/*
	작업 스케줄링 선택 문제 : 대표적인 그리디 알고리즘
		일찍 끝나는 순서로 정렬해 주어야 한다! 
*/

using namespace std;
#include <cstdio>
#include <utility>
#include <algorithm>
#include <set>

int N;
pair<int, int> A[100000];

struct _comp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		// 틀린 이유: 시작 시간과 종료 시간이 같을 수도 있으므로 시작 시간으로도 정렬해주어야 한다! ( [2, 3], [3, 3] )
		return a.second != b.second ? a.second < b.second : a.first < b.first;
	}
};

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &A[i].first, &A[i].second);
	}
	sort(A, A + N, _comp());

	int start = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		if (A[i].first < start)
			continue;
		start = A[i].second, ans += 1;
	}
	printf("%d", ans);
}