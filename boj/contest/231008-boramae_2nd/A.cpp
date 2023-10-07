using namespace std;
#include <bits/stdc++.h>

int main()
{
	int N, X;
	scanf("%d %d", &N, &X);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		int d;
		scanf("%d", &d);
		sum += d;
	}
	printf("%d", !(sum % X));
}