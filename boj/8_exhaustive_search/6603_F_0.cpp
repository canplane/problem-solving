#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    while (true) {
        int k;
        scanf("%d", &k);
        if (!k)
            break;
        vector<int> v(k);
        for (int i = 0; i < k; i++)
            scanf("%d", &v[i]);
        
        do {
            bool nonsense = false;
            for (int i = 0; i < 6 - 1; i++)
                if (!(v[i] <= v[i + 1])) {
                    nonsense = true;
                    break;
                }
            if (nonsense)
                continue;
            for (int i = 0; i < 6; i++)
                printf("%d ", v[i]);
            printf("\n");
        } while (next_permutation(v.begin(), v.end()));
        printf("\n");
    }
}