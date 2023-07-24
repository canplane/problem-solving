// 예상 대진표: https://school.programmers.co.kr/learn/courses/30/lessons/12985

using namespace std;
#include <cstdio>

int solution(int n, int a, int b)
{
	int ans = 0;
	a -= 1, b -= 1;
	while (a != b) {
		a >>= 1, b >>= 1, ans++;
	}
	return ans;
}

int main()
{
	solution(8, 4, 7);
}