// 17298에 더하여 비교 기준이 count로만 바뀐 문제.

using namespace std;
#include <cstdio>
#include <stack>

int N;
int A[1000000], cnt[1000001];
int B[1000000];

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		++cnt[A[i]];
	}

	stack<int> st;
	for (int i = N - 1; i >= 0; i--) {
		int x = A[i], y;
		bool b = false;
		while (!st.empty()) {
			y = st.top();
			if (cnt[x] < cnt[y]) {
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