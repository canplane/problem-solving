// 마지막부터 처음으로 내려오는 스택 문제

using namespace std;
#include <cstdio>
#include <stack>

int N;
int A[1000000];
int B[1000000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}

	stack<int> st;
	for (int i = N - 1; i >= 0; i--) {
		int x = A[i], y;
		bool b = false;
		while (!st.empty()) {
			y = st.top();
			if (x < y) {
				b = true;
				break;
			}
			st.pop();
		}
		B[i] = b ? y : -1;
		st.push(x);
	}

	for (int i = 0; i < N; i++) {
		printf("%d ", B[i]);
	}
}