/*
    -4 -3 -2 -1 0   1  2 3 4 5
    _____ _____ _ |   | ___ ___
                   l,r

    -4 -3 -2 -1 0   2 3 4 5
    _____ _____ _ | ___ ___
                r   l

	-4 -3 -2 -1 0
    _____ _____ _ |
                r   l

	  1  2 3 4 5
	|   | ___ ___
     l,r
 */

#include <cstdio>
#include <algorithm>

int v[9999], N; 

int main() {
	int i;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &v[i]);
	std::sort(v, v + N);

	int l, r;
	for (l = 0; l <= N - 1 && v[l] < 1; l++);
	for (r = N - 1; r >= 0 && v[r] > 1; r--);
    
	int ans = 0;
	for (i = 0; i < l; i += 2)
		ans += v[i] * ((i + 1 == l) ? 1 : v[i + 1]);
	for (i = l; i <= r; i++)
		ans += v[i];
	for (i = N - 1; i > r; i -= 2)
		ans += v[i] * ((i - 1 == r) ? 1 : v[i - 1]);
	printf("%d", ans);
}