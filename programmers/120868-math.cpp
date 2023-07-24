// 삼각형의 완성조건 (2): https://school.programmers.co.kr/learn/courses/30/lessons/120868

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> sides) {
	int &a = sides[0], &b = sides[1];
    int answer = (a + b) - abs(a - b) - 1;
    return answer;
}