using namespace std;
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

int ccw(pair<long, long> A, pair<long, long> B, pair<long, long> C)
{
	long tmp = (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
	return (int)max(min(tmp, 1L), -1L);
}
bool is_parallel(pair<long, long> A, pair<long, long> B, pair<long, long> C, pair<long, long> D)
{
	long tmp = (B.first - A.first) * (D.second - C.second) - (B.second - A.second) * (D.first - C.first);
	return !tmp;
}
bool intersect(pair<long, long> A, pair<long, long> B, pair<long, long> C, pair<long, long> D)
{
	int ans1 = ccw(A, B, C) * ccw(A, B, D);
	int ans2 = ccw(C, D, A) * ccw(C, D, B);
	
	if (ans1 == 0 && ans2 == 0)
		return !is_parallel(A, B, C, D) || (A <= D || C <= B);
	else
		return ans1 <= 0 && ans2 <= 0;
}

int N;
vector<pair<pair<long, long>, pair<long, long>>> v;

long t;
struct Line {
	int i;
	bool operator<(const Line& l) const {
		auto& [A, B] = v[i]; auto& [C, D] = v[l.i];
		double t1 = (double)(t - A.first) / (B.first - A.first);
		double t2 = (double)(t - C.first) / (D.first - C.first);
		return t1 * (B.second - A.second) + A.second < t2 * (D.second - C.second) + C.second;
	}
};
struct Event {
	int i;
	bool end;
	bool operator<(const Event& e) const {
		auto& A = !end ? v[i].first : v[i].second;
		auto& B = !e.end ? v[e.i].first : v[e.i].second;
		return A != B ? A < B : end < e.end;
	}
};

// Shmos-Hoey Algorithm
bool any_segments_intersect()
{
	vector<Event> E(2 * N);
	for (int i = 0; i < N; i++) {
		auto& [A, B] = v[i];
		E[2 * i] = { i, false }, E[2 * i + 1] = { i, true };
	}
	sort(E.begin(), E.end());

	multiset<Line> T;
	for (auto& s : E) {
		auto [A, B] = v[s.i];

		if (!s.end) {
			t = (v[s.i].first).first;
			auto it = T.insert({ s.i });
			if (it != T.begin()) {
				auto& [C, D] = v[prev(it)->i];
				if (intersect(A, B, C, D))	return true;
			}
			if (next(it) != T.end()) {
				auto& [C, D] = v[next(it)->i];
				if (intersect(A, B, C, D))	return true;
			}
		}
		else {
			t = (v[s.i].second).first;
			auto it = T.lower_bound({ s.i });
			if (it != T.begin() && next(it) != T.end()) {
				auto& [A, B] = v[prev(it)->i]; auto& [C, D] = v[next(it)->i];
				if (intersect(A, B, C, D))	return true;
			}
			T.erase(it);
		}
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	v.resize(N);

	for (int i = 0; i < N; i++) {
		pair<long, long> A, B;
		scanf("%ld %ld", &A.first, &A.second);
		scanf("%ld %ld", &B.first, &B.second);
		v[i] = { A, B };
	}

	for (int i = 0; i < N; i++) {
		auto [A, B] = v[i];
		if (A > B)	swap(A, B);
		v[i] = { A, B };
	}
	int ans1 = any_segments_intersect();

	for (int i = 0; i < N; i++) {
		auto [A, B] = v[i];
		A = { A.second, A.first }, B = { B.second, B.first };
		if (A > B)	swap(A, B);
		v[i] = { A, B };
	}
	int ans2 = any_segments_intersect();

	printf("%d", ans1 || ans2);
}