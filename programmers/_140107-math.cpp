// 점 찍기: https://school.programmers.co.kr/learn/courses/30/lessons/140107
// long 때문에 틀림

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long solution(int k, int _d) {
	long d = _d;

	long ans = 0;
	for (long x = 0; x <= d; x += k) {
		ans += 1 + (long)(sqrt(d * d - x * x) / k);
	}
	return ans;
}