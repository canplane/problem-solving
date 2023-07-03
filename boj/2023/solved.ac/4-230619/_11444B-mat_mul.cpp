using namespace std;
#include <cstdio>

#define MOD 1'000'000'007
long T[2][2];
void mul(long C[][2], long A[][2], long B[][2])
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			T[i][j] = 0;
			for (int k = 0; k < 2; k++)
				T[i][j] = (T[i][j] + A[i][k] * B[k][j]) % MOD;
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			C[i][j] = T[i][j];
}

long I[2][2] = {
	{ 1, 0 },
	{ 0, 1 }
};
void pow(long M[][2], long A[][2], long n)
{
	if (n == 0) {
		mul(M, I, I);
		return;
	}
	pow(M, A, n / 2);
	mul(M, M, M);
	if (n % 2)
		mul(M, M, A);
}

long A[2][2] = {
	{ 1, 1 },
	{ 1, 0 }
};
long P[2][2];
int main()
{
	long n;
	scanf("%ld", &n);

	pow(P, A, n);
	printf("%ld", P[0][1]);
}