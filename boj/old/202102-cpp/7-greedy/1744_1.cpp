/*
    -4 -3 -2 -1 0 1 2 3 4 5
    _____ _____ l r ___ ___

    -4 -3 -2 -1  0  2 3 4 5
    _____ _____  _  ___ ___
                l,r

	-4 -3 -2 -1  0
    _____ _____ l,r

	 1  2 3 4 5
	l,r ___ ___
 */

#include <cstdio>
#include <algorithm>

int seq[9999], N;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &seq[i]);
	std::sort(seq, seq + N);

	int ans = 0, l, r;
	for (l = 0; l < N - 1 && seq[l + 1] < 1; l += 2)
		ans += seq[l] * seq[l + 1];
	for (r = N - 1; r > 0 && seq[r - 1] > 1; r -= 2)
		ans += seq[r] * seq[r - 1];
	while (l <= r)
		ans += seq[l++];
	printf("%d", ans);
}