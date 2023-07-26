using namespace std;
#include <cstdio>

int N;
int D[100][100];

void floyd()
{
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (D[i][k] == 1 && D[k][j] == 1) {
					D[i][j] = 1;
				}
			}
		}
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &D[i][j]);
		}
	}
	floyd();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", D[i][j]);
		}
		printf("\n");
	}
}