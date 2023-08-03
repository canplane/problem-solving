using namespace std;
#include <bits/stdc++.h>

int M1, M2, M3, m1, m2, m3;

int main()
{
	int N;
	scanf("%d", &N);

	int a1, a2, a3, t1, t2, t3;
	while (N--) {
		scanf("%d %d %d", &a1, &a2, &a3);
		t1 = a1 + max(M1, M2), t2 = a2 + max(max(M1, M2), M3), t3 = a3 + max(M2, M3);
		M1 = t1, M2 = t2, M3 = t3;
		t1 = a1 + min(m1, m2), t2 = a2 + min(min(m1, m2), m3), t3 = a3 + min(m2, m3);
		m1 = t1, m2 = t2, m3 = t3;
	}
	printf("%d %d", max(max(M1, M2), M3), min(min(m1, m2), m3));
}