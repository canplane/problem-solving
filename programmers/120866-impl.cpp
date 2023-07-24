// 안전지대: https://school.programmers.co.kr/learn/courses/30/lessons/120866?language=cpp

#include <string>
#include <vector>

using namespace std;

int N;
bool B[102][102];
int solution(vector<vector<int>> A) {
	N = A.size();

	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (A[y - 1][x - 1]) {
				B[y - 1][x - 1] = B[y - 1][x] = B[y - 1][x + 1] = \
				B[y][x - 1] = B[y][x] = B[y][x + 1] = \
				B[y + 1][x - 1] = B[y + 1][x] = B[y + 1][x + 1] = \
				true;
			}
		}
	}

	int ans = 0;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			ans += !B[y][x];
		}
	}
	return ans;
}