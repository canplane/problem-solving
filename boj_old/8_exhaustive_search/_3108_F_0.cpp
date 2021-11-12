#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

set<pair<int, int>> horiz[1001], vert[1001];

int merge_horiz(int y, int Ax, int Bx) {
    auto next = horiz[y + 500].lower_bound({ Ax, Ax });
    auto prev = next;
    if (prev != horiz[y + 500].begin())
        prev--;

    if (next != horiz[y + 500].end())
        printf("next<%d %d> ", next->first, next->second);
    if (prev != horiz[y + 500].end())
        printf("prev<%d %d> ", prev->first, prev->second);
    printf("\n");

    int ret;
    if (prev != horiz[y + 500].begin() && Ax <= prev->second) {
        if (next != horiz[y + 500].end() && next->first <= Bx) {
            Ax = prev->first, Bx = next->second;
            horiz[y + 500].erase(prev), horiz[y + 500].erase(next), ret = -1;
        }
        else {
            Bx = max(prev->second, Bx);
            horiz[y + 500].erase(prev), ret = 0;
        }
    }
    else if (next != horiz[y + 500].end() && next->first <= Bx) {
        Bx = max(next->second, Bx);
        horiz[y + 500].erase(prev), ret = 0;
    }
    else
        ret = 1;

    horiz[y + 500].insert({ Ax, Bx });
    return ret;
}
int merge_vert(int x, int Ay, int By) {
    auto next = vert[x + 500].lower_bound({ Ay, Ay });
    auto prev = next;
    if (prev != vert[x + 500].begin())
        prev--;

    int ret;
    if (prev != vert[x + 500].begin() && Ay <= prev->second) {
        if (next != vert[x + 500].end() && next->first <= By) {
            Ay = prev->first, By = next->second;
            vert[x + 500].erase(prev), vert[x + 500].erase(next), ret = -1;
        }
        else {
            By = max(prev->second, By);
            vert[x + 500].erase(prev), ret = 0;
        }
    }
    else if (next != vert[x + 500].end() && next->first <= By) {
        By = max(next->second, By);
        vert[x + 500].erase(prev), ret = 0;
    }
    else
        ret = 1;
    
    vert[x + 500].insert({ Ay, By });
    return ret;
}

int main() {
    int N;
    scanf("%d", &N);

    int ans = 0;
    while (N--) {
        int Ax, Ay, Bx, By;
        scanf("%d %d %d %d", &Ax, &Ay, &Bx, &By);

        ans += merge_horiz(Ay, Ax, Bx);
        ans += merge_horiz(By, Ax, Bx);
        ans += merge_vert(Ax, Ay, By);
        ans += merge_vert(Bx, Ay, By);
    }
    printf("%d", ans);
}