/* 시점이 계속 움직인다고 생각. 그 시점마다 제일 빨리 끝나는 것 고르기 */

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Time {
    int start, end;  
};
struct cmp {
    bool operator()(const Time& t1, const Time& t2) const {
        return t1.end != t2.end ? t1.end < t2.end : t1.start < t2.start;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    vector<Time> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].start, &v[i].end);
    sort(v.begin(), v.end(), cmp());
    
    int ans = 0;
    int t = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].start < t)
            continue;
        ans++;
        t = v[i].end;
    }
    printf("%d", ans);   
}