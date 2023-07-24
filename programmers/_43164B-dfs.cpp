// 여행경로: https://school.programmers.co.kr/learn/courses/30/lessons/43164
// 엣지를 노드 기준으로 세우면 된다는 것을 생각도 못함...

using namespace std;
#include <bits/stdc++.h>

vector<vector<string>> tickets;
vector<string> answer;

bool vis[10000];
bool dfs(string s)
{
	answer.push_back(s);
	if (answer.size() == tickets.size() + 1) {
		return true;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == s && !vis[i]) {
			vis[i] = true;
			if (dfs(tickets[i][1])) {
				return true;
			}
			vis[i] = false;
		}
	}
	answer.pop_back();
	return false;
}

vector<string> solution(vector<vector<string>> _tickets) {
	tickets = _tickets;
	sort(begin(tickets), end(tickets));

	dfs("ICN");
	return answer;
}