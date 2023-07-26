/*
	* 오래 걸린 요인 (1시간 반) : 솔직히 어떻게 짜야 할지 감도 안 잡혔음.
	* 틀린 요인 : (질문 게시판으로 도움 얻음) 일단 넣어보고 모든 경우가 다 실패했을 때 다시 0으로 돌리는 걸 하지 않아서.
	* 참고 사항 : 다음 후보 만들 때, 배열 말고 매번 벡터 만들면 두 배 이상 오래 걸림 (70 ms -> 170 ms). STL을 인수로 넘기거나 리턴하는 건 웬만해선 하지 말자.
*/

using namespace std;
#include <cstdio>
#include <vector>
#include <utility>

int A[9][9];

void make_candidates(bool flag[], int y0, int x0)
{
	for (int i = 1; i < 10; i++)
		flag[i] = true;
	
	for (int x = 0; x < 9; x++)
		flag[A[y0][x]] = false;
	for (int y = 0; y < 9; y++)
		flag[A[y][x0]] = false;
	for (int dy = 0; dy < 3; dy++) {
		for (int dx = 0; dx < 3; dx++)
			flag[A[y0 / 3 * 3 + dy][x0 / 3 * 3 + dx]] = false;
	}
}

vector<pair<int, int>> zeros;
bool dfs(int i)
{
	if (i == zeros.size())
		return true;

	auto [y0, x0] = zeros[i];

	bool flag[10];
	make_candidates(flag, y0, x0);
	for (int w = 1; w < 10; w++) {
		if (flag[w]) {
			A[y0][x0] = w;
			if (dfs(i + 1))
				return true;
			A[y0][x0] = 0;	// 틀린 요인!!!
		}
	}
	return false;
}

int main()
{
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++) {
			scanf("%d", &A[y][x]);
			if (!A[y][x])
				zeros.push_back({ y, x });
		}
	}

	dfs(0);
	for (int y = 0; y < 9; y++) {
		for (int x = 0; x < 9; x++)
			printf("%d ", A[y][x]);
		printf("\n");
	}
}