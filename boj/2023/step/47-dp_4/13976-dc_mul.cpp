using namespace std;
#include <cstdio>

#define M 1'000'000'007

long S[2][2], I[2][2] = { { 1, 0 }, { 0, 1 } };
long A[2][2] = { { 4, -1 }, { 1, 0 } }, a0 = 1, a1 = 3;
void mul(long C[][2], long A[][2], long B[][2])
{
	long T[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			T[i][j] = 0;
			for (int k = 0; k < 2; k++) {
				T[i][j] = (T[i][j] + (A[i][k] * B[k][j]) % M) % M; 
			}
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			C[i][j] = T[i][j];
		}
	}
}
void dc(long n)
{
	if (n == 0) {
		mul(S, I, I);
		return;
	}
	dc(n / 2), mul(S, S, S);
	if (n % 2) {
		mul(S, S, A);
	}
}

int main()
{
	long N;
	scanf("%ld", &N);

	if (N % 2) {
		printf("0");
		return 0;
	}
	dc(N / 2);
	long ans = ((S[1][0] * a1) % M + (S[1][1] * a0) % M) % M;
	printf("%ld", (ans + M) % M);	// 음수 나머지
}