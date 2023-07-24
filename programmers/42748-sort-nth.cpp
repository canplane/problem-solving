// K번째수: https://school.programmers.co.kr/learn/courses/30/lessons/42748

using namespace std;
#include <bits/stdc++.h>

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	for (auto cmd : commands) {
		vector<int> A;
		for (int i = cmd[0] - 1; i < cmd[1]; i++) {
			A.push_back(array[i]);
		}
		nth_element(A.begin(), A.begin() + cmd[2] - 1, A.end());
		answer.push_back(A[cmd[2] - 1]);
	}
	return answer;
}