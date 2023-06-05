using namespace std;
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>

// Shmos-Hoey Algorithm
long t;
struct Line {
	pair<long, long> P, Q;
	bool operator<(const Line& l) const {
		auto& [A, B] = *this; auto& [C, D] = l;
		double m1 = (double)(B.second - A.second) / (B.first - A.first);
		double m2 = (double)(D.second - C.second) / (D.first - C.first);
		return m1 * (t - A.first) + A.second < m2 * (t - C.first) + C.second;
	}
};
struct Event {
	pair<long, long> P; bool end;
	int i;
	bool operator<(const Event& e) const { return P != e.P ? P < e.P : end < e.end; }
};

int N;
vector<Line> L;

int ccw(pair<long, long> P, pair<long, long> Q, pair<long, long> R)
{
	long ret = (Q.first - P.first) * (R.second - P.second) - (Q.second- P.second) * (R.first - P.first);
	if (ret > 0)	return 1;
	if (ret < 0)	return -1;
	return 0;
}
bool intersect(Line a, Line b)
{
	auto& [A, B] = a; auto& [C, D] = b;
	int ans1 = ccw(A, B, C) * ccw(A, B, D);
	int ans2 = ccw(C, D, A) * ccw(C, D, B);
	
	if (ans1 == 0 && ans2 == 0)
		return A <= D && C <= B;
	else
		return ans1 <= 0 && ans2 <= 0;
}

bool any_segments_intersect()
{
	vector<Event> E(2 * N);
	for (int i = 0; i < N; i++) {
		auto& [A, B] = L[i];
		E[2 * i] = { A, false, i }, E[2 * i + 1] = { B, true, i };
	}
	sort(E.begin(), E.end());

	multiset<Line> T;
	for (auto& [P, end, i] : E) {
		t = P.first;
		if (!end) {
			auto it = T.insert(L[i]);
			if (it != T.begin()) {
				if (intersect(L[i], *prev(it)))
					return true;
			}
			if (next(it) != T.end()) {
				if (intersect(L[i], *next(it)))
					return true;
			}
		}
		else {
			auto it = T.lower_bound(L[i]);	// find는 안 되나 봄.
			if (it != T.begin() && next(it) != T.end()) {
				if (intersect(*prev(it), *next(it)))
					return true;
			}
			T.erase(it);
		}
	}
	return false;
}

int main()
{
	scanf("%d", &N);
	L.resize(N);

	for (int i = 0; i < N; i++) {
		pair<long, long> A, B;
		scanf("%ld %ld %ld %ld", &A.first, &A.second, &B.first, &B.second);
		if (A > B)	swap(A, B);
		L[i] = { A, B };
	}
	printf("%d", any_segments_intersect());
}