/* 짧은 순서대로만 해서 틀렸다. */

#include <cstdio>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second - p1.first < p2.second - p2.first;
    }
};

int main() {
    int N;
    scanf("%d", &N);
    
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", &v[i].first, &v[i].second);
    sort(v.begin(), v.end(), cmp());

    /*for (auto it = v.begin(); it != v.end(); it++)
        printf("<%d %d> ", it->first, it->second);
    printf("\n\n");*/

    int ans = 0;
    list<pair<int, int>> occu;
    for (int i = 0; i < N; i++) {
        auto it = occu.begin();
        bool possible = true;
        while (it != occu.end()) {  // 이거 판정법이 어렵다..
            if (v[i].first <= it->first) {
                if (!(v[i].second <= it->first))
                    possible = false;
                break;
            }
            it++;
        }
        if (possible) {
            occu.insert(it, v[i]);
            ans++;
        }
        /*for (auto it = occu.begin(); it != occu.end(); it++)
            printf("<%d %d> ", it->first, it->second);
        printf("\n");*/
    }
    printf("%d", ans);
}