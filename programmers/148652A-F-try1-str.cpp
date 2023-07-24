// 유사 칸토어 비트열: https://school.programmers.co.kr/learn/courses/30/lessons/148652

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, long long l, long long r) {
	string s = "1";
	for (int i = 0; i < n; i++) {
		string t;
		for (auto& c : s) {
			if (c == '1') {
				t += "11011";
			}
			else {
				t += "00000";
			}
		}
		s = t;
	}

	int answer = 0;
	for (long long i = l - 1; i < r; i++) {
		if (s[i] == '1') {
			answer++;
		}
	}
    return answer;
}