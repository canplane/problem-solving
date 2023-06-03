using namespace std;
#include <cstdio>
#include <algorithm>

int P[1000];
int N;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &P[i]);
	}
	sort(P, P + N);
	for (int i = 1; i < N; i++) {
		P[i] += P[i - 1];
	}
	for (int i = 1; i < N; i++) {
		P[i] += P[i - 1];
	}
	printf("%d", P[N - 1]);
}