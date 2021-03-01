/* string이 생각보다 안 무겁네.
 * 123456780 대신 123456789 해야 한다. 안 그러면 012345678은 12345678로 되어서 to_string() 하면 8자리가 되니까.
 */

#include <cstdio>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map<int, bool> visit;
int dy[4] = { -1, 1, 0, 0 }, dx[4] = { 0, 0, -1, 1 };

int main() {
    int d = 0, tmp;
    for (int i = 0; i < 9; i++) {
        scanf("%d", &tmp);
        d = 10 * d + (tmp ? tmp : 9);
    }
    
    int ans = 0, seg = 1;
    queue<int> q;
    visit[d] = true, q.push(d);
    while (!q.empty()) {
        int next_seg = 0;
        string s;
        while (seg--) {
            d = q.front(), q.pop();
            if (d == 123456789) {
                printf("%d", ans);
                return 0;
            }

            s = to_string(d);
            int k = s.find('9');
            int y = k / 3, x = k % 3;

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny < 0 || ny >= 3 || nx < 0 || nx >= 3)
                    continue;
                int nk = 3 * ny + nx;
                swap(s[nk], s[k]);
                if (!visit[d = stoi(s)])
                    visit[d] = true, q.push(d), next_seg++;
                swap(s[nk], s[k]);
            }
        }
        ans++, seg = next_seg;
    }
    printf("%d", -1);
}