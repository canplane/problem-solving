// BOJ 12850 본대 산책2
// 인접 행렬 날먹 문제 (분할 정복을 이용한 거듭제곱)

using namespace std;
#include <bits/stdc++.h>


#define DIV	1'000'000'007

long I[8][8];
void mul(long D[][8], long S1[][8], long S2[][8])
{
	long _D[8][8];
	memset(_D, 0, sizeof(_D));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			for (int k = 0; k < 8; k++)
				_D[i][j] = (_D[i][j] + (S1[i][k] * S2[k][j]) % DIV) % DIV;
	memcpy(D, _D, sizeof(_D));
}
void pow(long D[][8], long S[][8], int n)
{
	if (!n)	{
		mul(D, I, I);
		return;
	}
	pow(D, S, n / 2);
	mul(D, D, D);
	if (n % 2)
		mul(D, D, S);
}


vector<int> adj[8] = {
	{ 1, 2 },
	{ 0, 2, 3 },
	{ 0, 1, 3, 4 },
	{ 1, 2, 4, 5 },
	{ 2, 3, 5, 7 },
	{ 3, 4, 6 },
	{ 5, 7 },
	{ 4, 6 }
};
long A[8][8], B[8][8];

int main()
{
	for (int i = 0; i < 8; i++) {
		I[i][i] = 1;
		for (int j : adj[i])
			A[i][j] = 1;
	}

	int n;
	scanf("%d", &n);
	pow(B, A, n);
	printf("%ld", B[0][0]);
}