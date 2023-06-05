using namespace std;
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>

struct _comp_hi {
	bool operator()(const pair<pair<long, long>, pair<long, long>>& a, const pair<pair<long, long>, pair<long, long>>& b) const {
		pair<long, long> A = (a.second), B = (b.second);
		return A < B;
	}
};
struct _comp_y_hi {
	bool operator()(const pair<pair<long, long>, pair<long, long>>& a, const pair<pair<long, long>, pair<long, long>>& b) const {
		pair<long, long> A = { (a.second).second, (a.second).first }, B = { (b.second).second, (b.second).first };
		return A < B;
	}
};
struct _comp_y_lo {
	bool operator()(const pair<pair<long, long>, pair<long, long>>& a, const pair<pair<long, long>, pair<long, long>>& b) const {
		pair<long, long> A = { (a.first).second, (a.first).first }, B = { (b.first).second, (b.first).first };
		return A < B;
	}
};


vector<pair<pair<long, long>, pair<long, long>>> v;

pair<pair<long, long>, pair<long, long>> f(pair<pair<long, long>, pair<long, long>> p) {
	auto [A, B] = p;
	if (A > B)	swap(A, B);
	return { A, B };
}
pair<pair<long, long>, pair<long, long>> f_y(pair<pair<long, long>, pair<long, long>> p) {
	auto [A, B] = p;
	A = { A.second, A.first }, B = { B.second, B.first };
	if (A > B)	swap(A, B);
	A = { A.second, A.first }, B = { B.second, B.first };
	return { A, B };
}

int ccw(pair<long, long> A, pair<long, long> B, pair<long, long> C)
{
	long tmp = (B.first - A.first) * (C.second - A.second) - (B.second - A.second) * (C.first - A.first);
	return (int)max(min(tmp, 1L), -1L);
}
bool intersect(pair<long, long> A, pair<long, long> B, pair<long, long> C, pair<long, long> D)
{
	long tmp = (B.first - A.first) * (D.second - C.second) - (B.second - A.second) * (D.first - C.first);
	return !!tmp;
}

int solve(pair<long, long> A, pair<long, long> B, pair<long, long> C, pair<long, long> D)
{
	int ans1 = ccw(A, B, C) * ccw(A, B, D);
	int ans2 = ccw(C, D, A) * ccw(C, D, B);
	
	if (ans1 == 0 && ans2 == 0) {
		if (intersect(A, B, C, D) || (A <= D || C <= B))
			return 1;
		else
			return 0;
	}
	else if (ans1 <= 0 && ans2 <= 0)
		return 1;
	else
		return 0;
}


int sweep()
{
	int ans = 0;

	auto it = v.begin();

	set<pair<pair<long, long>, pair<long, long>>, _comp_y_hi> v_y_hi;
	//set<pair<pair<long, long>, pair<long, long>>, _comp_y_lo> v_y_lo;

	v_y_hi.insert(v[0]);//, v_y_lo.insert(v[0]);
	
	for (int i = 1; i < v.size(); i++) {
		while (it->second < v[i].first) {
			auto p_y = f_y(*it++);
			v_y_hi.erase(p_y);//, v_y_lo.erase(p_y);
		}

		auto [A, B] = v[i];

		auto p_y = f_y(v[i]);
		auto [y_m, y_M] = p_y;

		auto it_y = v_y_hi.lower_bound({ y_m, y_m });
		//auto it_y_r = v_y_hi.upper_bound(*v_y_lo.upper_bound({ y_M, y_M }));
		auto it_y_r = v_y_hi.end();
		while (it_y != it_y_r) {
			auto [C, D] = f(*it_y++);
			ans |= solve(A, B, C, D);
			if (ans)	return ans;
		}
		v_y_hi.insert(p_y);//, v_y_lo.insert(p_y);
	}

	return ans;
}

int main()
{
	int N;
	scanf("%d", &N);
	v.resize(N);

	for (int i = 0; i < v.size(); i++) {
		pair<long, long> A, B;
		scanf("%ld %ld", &A.first, &A.second);
		scanf("%ld %ld", &B.first, &B.second);
		v[i] = f({ A, B });
	}
	sort(v.begin(), v.end(), _comp_hi());

	printf("%d", sweep());
}

