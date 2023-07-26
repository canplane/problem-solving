using namespace std;
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <cmath>

vector<pair<int, int>> v_x;

struct comp_y {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
		// const after function : 이 클래스 메서드 안에서는 어떤 변수도 바꿀 수 없음.
		pair<int, int> aT = { a.second, a.first }, bT = { b.second, b.first };
		return aT < bT;
	}
};
set<pair<int, int>, comp_y> v_xy;

long dist(pair<int, int> a, pair<int, int> b)
{
	return (long)(pow((long)a.first - b.first, 2) + pow((long)a.second - b.second, 2));
}

long sweep()
{
	auto it_x = v_x.begin();

	long min_d = dist(v_x[1], v_x[0]);
	v_xy.insert(v_x[0]), v_xy.insert(v_x[1]);
	for (int i = 2; i < v_x.size(); i++) {
		while (v_x[i].first - it_x->first > sqrt(min_d))
			v_xy.erase(*it_x++);	// set의 erase는 iterator 말고 key도 조회 가능
		
		pair<int, int> xy_lower = { -10000, v_x[i].second - sqrt(min_d) };
		pair<int, int> xy_upper = { 10000, v_x[i].second + sqrt(min_d) };
		// std::lower_bound(set, ...) 하면 안 된다. (느림!)
		// [C++ Difference between std::lower_bound and std::set::lower_bound?]
		// 		https://stackoverflow.com/questions/31821951/c-difference-between-stdlower-bound-and-stdsetlower-bound
		auto it_xy = v_xy.lower_bound(xy_lower);
		auto it_xy_r = v_xy.upper_bound(xy_upper);
		while (it_xy != it_xy_r)
			min_d = min(min_d, dist(v_x[i], *it_xy++));
		
		v_xy.insert(v_x[i]);
	}
	return min_d;
}

int main()
{
	int n;
	scanf("%d", &n);
	v_x.resize(n);

	int x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		v_x[i] = { x, y };
	}
	sort(v_x.begin(), v_x.end());

	printf("%ld", sweep());
}